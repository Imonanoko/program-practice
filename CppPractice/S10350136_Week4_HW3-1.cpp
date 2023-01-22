#include<iostream>
using namespace std;
int main(void){
    int num=1;
    string star="*";
    while(num<6){
        string star1="";
        for(int i=0;i<num;i++){
            star1+=star;
        }
        num++;
        cout<<star1<<endl;
    }
    num--;
    do{
        num--;
        string star1="";
        for(int i=0;i<num;i++){
            star1+=star;
        }
        cout<<star1<<endl;}
    while(num>0);
}