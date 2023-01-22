#include<iostream>
#include<cmath>
using namespace std;
int main(void){
    string a;
    while(cin>>a){
        if(a=="0"){break;}
        int oddtotal=0,eventotal=0;
        for(int i=0;i<a.length();i+=2){
            oddtotal+=(int) a[i]-48;
        }
        for(int i=1;i<a.length();i+=2){
            eventotal+=(int) a[i]-48;
        }
        if((eventotal-oddtotal)%11==0){
            cout<<a<<" is a multiple of 11."<<endl;
        }
        else{
            cout<<a<<" is not a multiple of 11."<<endl;
        }

    }
}