#include<iostream>

using namespace std;
int main(void){
    int a,b;
    while(cin>>a>>b){
        int carry=0,t=0;
        if(a==0&&b==0){break;}
        while(a!=0||b!=0){
            if((a%10)+(b%10)+t>=10){
                carry++;
                t=1;
            }
            else{t=0;}
            a=a/10;
            b=b/10;
        }
        if(carry==0){
            cout<<"No carry operation."<<endl;
        }
        else if(carry==1){cout<<"1 carry operation."<<endl;}
        else{cout<<carry<<" carry operations."<<endl;}
    }
}