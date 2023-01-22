#include<iostream>
#include<string>
using namespace std;
int main(void){
    string a;
    int num;
    while(getline(cin,a)){
        num=0;
        for (int i=0;i<a.length();i++){
            if(!isalpha(a[i])&&isalpha(a[i+1])){
                num++;
            }
            else{continue;}
        }
        num++;
        cout<<num<<endl;
    }
}