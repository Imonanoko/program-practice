#include<iostream>
using namespace std;
bool isPalindrome(string);
int main(void){
	string str;
	cin>>str;
	if (isPalindrome(str)){
		cout<<str<<" is palindrome";
	}
	else{
		cout<<str<<" is not palindrome";
	}
}
bool isPalindrome(string str){
	string str1="";
	for(int i=(str.length()-1);i>=0;i--){
		str1+=str[i];
	}
	if(str1==str){
		return 1;
	}
	else{
		return 0;
	}
}
