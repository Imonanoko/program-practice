#include<iostream>
using namespace std;
int main(void){
    int a;
    while(cin>>a){
        int total=0,m=0;
        while(a+m>=3){//擁有的瓶數大於等於3時不用借瓶子換
            total+=a;//總共喝了幾瓶
            m+=a;//喝掉的時候換變空瓶
            a=m/3;//可以換的可樂數
            m%=3;//剩餘的空瓶
        }
        total+=a;
        if(a+m==2){//只有剩兩個空瓶的時候能借因為才有辦法還
            total++;
        }
        cout<<total<<endl;
    }
}