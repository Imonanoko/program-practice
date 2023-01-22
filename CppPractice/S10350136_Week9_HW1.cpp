#include<iostream>
using namespace std;
void password(string);
int main(void){
	string str;
	cout<<"Enter your password:";
	cin>>str;
	password(str);
}
void password(string str){
	int alpha,num=0;
	bool determine=1;
	if(str.length()!=8){
		determine=0;
	}
	for (int i=0;i<str.length();i++){
		if (isalpha(str[i])){
			alpha+=1;
		}
		else if(isdigit(str[i])){
			num+=1;
		}
		else{
			determine=0;
		}
	}
	if(num<2){
		determine=0;
	}
	if (determine){
	cout<<"valid password";
	}
	else{
		cout<<"invalid password";	
	}
}
