#include<iostream>
using namespace std;
string reverse(string a){
    string answer="";
    for(int i=0;i<a.length();i++){
        answer=a[i]+answer;
    }
    return answer;
}
int main(void){
    string x;
    cout<<"Enter a string:";
    cin>>x;
    cout<<reverse(x);
}