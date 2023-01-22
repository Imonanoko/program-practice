#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "winsock2.h"
#include <time.h>
#include <queue>
#include <hash_set>

#pragma comment(lib, "ws2_32.lib") 
using namespace std;

#define DEFAULT_PAGE_BUF_SIZE 1048576
queue<string> hrefUrl;
hash_set<string> visitedUrl;
hash_set<string> visitedImg;
int depth=0;
int g_ImgCnt=1;

//解析URL，解析出主機名，資源名
bool ParseURL( const string & url, string & host, string & resource){
	if ( strlen(url.c_str()) > 2000 ) {
		return false;
	}

	const char * pos = strstr( url.c_str(), "http://" );
	if( pos==NULL ) pos = url.c_str();
	else pos += strlen("http://");
	if( strstr( pos, "/")==0 )
		return false;
	char pHost[100];
	char pResource[2000];
	sscanf( pos, "%[^/]%s", pHost, pResource );
	host = pHost;
	resource = pResource;
	return true;
}

//使用Get請求，得到響應
bool GetHttpResponse( const string & url, char * &response, int &bytesRead ){
	string host, resource;
	if(!ParseURL( url, host, resource )){
		cout << "Can not parse the url"<<endl;
		return false;
	}
	
	//建立socket
	struct hostent * hp= gethostbyname( host.c_str() );
	if( hp==NULL ){
		cout<< "Can not find host address"<<endl;
		return false;
	}

	SOCKET sock = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if( sock == -1 || sock == -2 ){
		cout << "Can not create sock."<<endl;
		return false;
	}

	//建立伺服器地址
	SOCKADDR_IN sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons( 80 );
	//char addr[5];
	//memcpy( addr, hp->h_addr, 4 );
	//sa.sin_addr.s_addr = inet_addr(hp->h_addr);
	memcpy( &sa.sin_addr, hp->h_addr, 4 );

	//建立連線
	if( 0!= connect( sock, (SOCKADDR*)&sa, sizeof(sa) ) ){
		cout << "Can not connect: "<< url <<endl;
		closesocket(sock);
		return false;
	};

	//準備傳送資料
	string request = "GET " + resource + " HTTP/1.1\r\nHost:" + host + "\r\nConnection:Close\r\n\r\n";

	//傳送資料
	if( SOCKET_ERROR ==send( sock, request.c_str(), request.size(), 0 ) ){
		cout << "send error" <<endl;
		closesocket( sock );
		return false;
	}

	//接收資料
	int m_nContentLength = DEFAULT_PAGE_BUF_SIZE;
	char *pageBuf = (char *)malloc(m_nContentLength);
    memset(pageBuf, 0, m_nContentLength);

    bytesRead = 0;
	int ret = 1;
	cout <<"Read: ";
    while(ret > 0){
        ret = recv(sock, pageBuf + bytesRead, m_nContentLength - bytesRead, 0);
        
        if(ret > 0)
        {
            bytesRead += ret;
        }

		if( m_nContentLength - bytesRead<100){
			cout << "\nRealloc memorry"<<endl;
			m_nContentLength *=2;
			pageBuf = (char*)realloc( pageBuf, m_nContentLength);       //重新分配記憶體
		}
		cout << ret <<" ";
    }
	cout <<endl;

    pageBuf[bytesRead] = '\0';
	response = pageBuf;
	closesocket( sock );
	return true;
	//cout<< response <<endl;
}

//提取所有的URL以及圖片URL
void HTMLParse ( string & htmlResponse, vector<string> & imgurls, const string & host ){
	//找所有連線，加入queue中
	const char *p= htmlResponse.c_str();
	char *tag="href=\"";
	const char *pos = strstr( p, tag );
	ofstream ofile("url.txt", ios::app);
	while( pos ){
		pos +=strlen(tag);
		const char * nextQ = strstr( pos, "\"" );
		if( nextQ ){
			char * url = new char[ nextQ-pos+1 ];
			//char url[100]; //固定大小的會發生緩衝區溢位的危險
			sscanf( pos, "%[^\"]", url);
			string surl = url;  // 轉換成string型別，可以自動釋放記憶體
			if( visitedUrl.find( surl ) == visitedUrl.end() ){
				visitedUrl.insert( surl );
				ofile << surl<<endl;
				hrefUrl.push( surl );
			}
			pos = strstr(pos, tag );
			delete [] url;  // 釋放掉申請的記憶體
		}
	}
	ofile << endl << endl;
	ofile.close();

	tag ="<img ";
	const char* att1= "src=\"";
	const char* att2="lazy-src=\"";
	const char *pos0 = strstr( p, tag );
	while( pos0 ){
		pos0 += strlen( tag );
		const char* pos2 = strstr( pos0, att2 );
		if( !pos2 || pos2 > strstr( pos0, ">") ) {
			pos = strstr( pos0, att1);
			if(!pos) {
				pos0 = strstr(att1, tag );
			continue;
			} else {
				pos = pos + strlen(att1);
			}
		}
		else {
			pos = pos2 + strlen(att2);
		}

		const char * nextQ = strstr( pos, "\"");
		if( nextQ ){
			char * url = new char[nextQ-pos+1];
			sscanf( pos, "%[^\"]", url);
			cout << url<<endl;
			string imgUrl = url;
			if( visitedImg.find( imgUrl ) == visitedImg.end() ){
				visitedImg.insert( imgUrl );
				imgurls.push_back( imgUrl );
			}
			pos0 = strstr(pos0, tag );
			delete [] url;
		}
	}
	cout << "end of Parse this html"<<endl;
}

//把URL轉化為檔名
string ToFileName( const string &url ){
	string fileName;
	fileName.resize( url.size());
	int k=0;
	for( int i=0; i<(int)url.size(); i++){
		char ch = url[i];
		if( ch!='\\'&&ch!='/'&&ch!=':'&&ch!='*'&&ch!='?'&&ch!='"'&&ch!='<'&&ch!='>'&&ch!='|')
			fileName[k++]=ch;
	}
	return fileName.substr(0,k) + ".txt";
}

//下載圖片到img資料夾
void DownLoadImg( vector<string> & imgurls, const string &url ){

	//生成儲存該url下圖片的資料夾
	string foldname = ToFileName( url );
	foldname = "./img/"+foldname;
	if(!CreateDirectory( foldname.c_str(),NULL ))
		cout << "Can not create directory:"<< foldname<<endl;
	char *image;
	int byteRead;
	for( int i=0; i<imgurls.size(); i++){
		//判斷是否為圖片，bmp，jgp，jpeg，gif 
		string str = imgurls[i];
		int pos = str.find_last_of(".");
		if( pos == string::npos )
			continue;
		else{
			string ext = str.substr( pos+1, str.size()-pos-1 );
			if( ext!="bmp"&& ext!="jpg" && ext!="jpeg"&& ext!="gif"&&ext!="png")
				continue;
		}
		//下載其中的內容
		if( GetHttpResponse(imgurls[i], image, byteRead)){
			if ( strlen(image) ==0 ) {
				continue;
			}
			const char *p=image;
			const char * pos = strstr(p,"\r\n\r\n")+strlen("\r\n\r\n");
			int index = imgurls[i].find_last_of("/");
			if( index!=string::npos ){
				string imgname = imgurls[i].substr( index , imgurls[i].size() );
				ofstream ofile( foldname+imgname, ios::binary );
				if( !ofile.is_open() )
					continue;
				cout <<g_ImgCnt++<< foldname+imgname<<endl;
				ofile.write( pos, byteRead- (pos-p) );
				ofile.close();
			}
			free(image);
		}
	}
}



//廣度遍歷
void BFS( const string & url ){
	char * response;
	int bytes;
	// 獲取網頁的相應，放入response中。
	if( !GetHttpResponse( url, response, bytes ) ){
		cout << "The url is wrong! ignore." << endl;
		return;
	}
	string httpResponse=response;
	free( response );
	string filename = ToFileName( url );
	ofstream ofile( "./html/"+filename );
	if( ofile.is_open() ){
		// 儲存該網頁的文字內容
		ofile << httpResponse << endl;
		ofile.close();
	}
	vector<string> imgurls;
	//解析該網頁的所有圖片連結，放入imgurls裡面
	HTMLParse( httpResponse,  imgurls, url );
	
	//下載所有的圖片資源
	DownLoadImg( imgurls, url );
}

void main()
{
	//初始化socket，用於tcp網路連線
    WSADATA wsaData;
    if( WSAStartup(MAKEWORD(2,2), &wsaData) != 0 ){
        return;
    }

	// 建立資料夾，儲存圖片和網頁文字檔案
	CreateDirectory( "./img",0);
	CreateDirectory("./html",0);
	//string urlStart = "http://hao.360.cn/meinvdaohang.html";

	// 遍歷的起始地址
	// string urlStart = "http://www.wmpic.me/tupian";
	string urlStart = "http://item.taobao.com/item.htm?spm=a230r.1.14.19.sBBNbz&id=36366887850&ns=1#detail";
	
	// 使用廣度遍歷
	// 提取網頁中的超連結放入hrefUrl中，提取圖片連結，下載圖片。
	BFS( urlStart );

	// 訪問過的網址儲存起來
	visitedUrl.insert( urlStart );

	while( hrefUrl.size()!=0 ){
		string url = hrefUrl.front();  // 從佇列的最開始取出一個網址
		cout << url << endl;
		BFS( url );					  // 遍歷提取出來的那個網頁，找它裡面的超連結網頁放入hrefUrl，下載它裡面的文字，圖片
		hrefUrl.pop();                 // 遍歷完之後，刪除這個網址
	}
    WSACleanup();
    return;
}