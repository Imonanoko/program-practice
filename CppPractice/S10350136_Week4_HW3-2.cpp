#include<iostream>
using namespace std;
int main(void){
    int num=5;
    string star="*";
    while(num>0){
        string star1="";
        for (int i=0;i<num;i++){
            star1+=star;
        }
        num--;
        cout<<star1<<endl;
    }
    num++;
    do
    {
        string star1="";
        num++;
        for(int i=0;i<num;i++){
            star1+=star;
        }
        cout<<star1<<endl;
    } while (num<5);
    
}