#include<iostream>
using namespace std;
int main(void){
    cout<<"請輸入20個整數";
    int a,even=0,odd=0;
    for (int i=0;i<20;i++){
        cin>>a;
        if (a%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout<<"偶數有"<<even<<"個"<<endl<<"奇數有"<<odd<<"個";
}