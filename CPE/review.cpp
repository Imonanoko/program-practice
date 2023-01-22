#include<iostream>
using namespace std;
int main(void){
    string str="to_string(a)",ans="";
	for(int i=str.length()-1;i>=0;i--){
		ans+=str[i];
	}
    cout<<ans;
}