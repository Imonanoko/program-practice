#include<iostream>
using namespace std;
int main(void){
	string s[101];
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
			if(s[j].length()<=j){
				count++;
			}
			else{
				cout<<string(count,' ')<<s[j][i];
			}
		}
		cout<<endl;
	}
}