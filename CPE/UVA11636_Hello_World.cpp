#include<iostream>
#include<math.h>
using namespace std;
double PowerOf2(int time){
    return pow(2,time);//回傳2的time次方
}
int main(void){
    int N,Case=0;
    while(cin>>N){
        Case++;
        if(N<0){break;}//輸入N直到輸入的質小於0
        int i=0;
        while(1){
            if(PowerOf2(i)>=N){//偵測何時會小於等於2的i次方
                cout<<"Case "<<Case<<": "<<i<<endl;
                break;
            }
            i++;
        }
    }
}