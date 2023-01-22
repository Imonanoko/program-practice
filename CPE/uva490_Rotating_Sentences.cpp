// #include <iostream>
// #include <string>
// using namespace std;
 
// int main()
// {
//     string a,is1[100]={""};//輸入用字串 
//     int i=0,t;//方便用 
//     int num,maxlen=0;//num計算有幾個句子 
//                      //maxlen計算最長句子長度 
//     while(getline(cin,a))//輸入資料 
//     {
//     	is1[i]=a;
//         if(is1[i].length()>maxlen)//取得最長句子的長度 
//         {
//             maxlen=is1[i].length();
//         }
//         i++;
//     }
     
//     num=i;//紀錄句子數量 
     
//     for(i=0;i<maxlen;i++)//開始翻轉囉 
//     {                    //i代表列 
//         int gap=0;//計算空白用的 
//         for(t=num-1;t>=0;t--)//t代表行 
//         {                    //num代表句子數量，所以t必須減1才符合陣列要求 
//             if(i>=is1[t].length())//如果超出該句長度 
//             {                     //就先計算要以多少空白作為代替 
//                 gap++;
//             }
//             else
//             {
//                 while(gap>0)//先輸出空白以代替完結句子 
//                 {
//                     cout<<" ";
//                     gap--;
//                 }
//                 cout<<is1[t][i];//再輸出該句子的字 
//             }
//         }
//         cout<<endl;//換行 
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main(void){
	string s[101]={};
	int index=0,maxlen=0;
	while(getline(cin,s[index])){
		if(s[index].length()>=maxlen){
			maxlen=s[index].length();
		}
		index++;
	}
	for(int i = 0;i<maxlen;i++){
		int count=0;
		for(int j = index-1;j>=0;j--){
			if(s[j].length()<=i){
				count++;
			}
			else{
				cout<<string(count,' ')<<s[j][i];
				count=0;
			}
		}
		cout<<endl;
	}
}