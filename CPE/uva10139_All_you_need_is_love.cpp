#include<iostream>
using namespace std;
// int gcd(int a,int b){
//     int c=max(a,b);
//     int d=min(a,b);
//     if(d==0){return 0;}
//     a=c;
//     b=d;
//     while(b!=0){
//         int mut=a/b;
//         int temp=b;
//         b=a-mut*b;
//         a=temp;
//     }
//     return a;
// }
int gcd(int a,int b){
    int nummax=max(a,b);
    int nummin=min(a,b);
    if(!nummin){
        return nummax;
    }
    return gcd(nummax%nummin,nummin);
}
int main(void){
    int time,count=1;
    cin>>time;
    while(time--){
        string S,L;
        cin>>S>>L;
        int decS = stoi(S,0,2);
        int decL = stoi(L,0,2);
        if(gcd(decL,decS)!=1){
            cout<<"Pair #"<<count++<<": All you need is love!"<<endl;
        }
        else{
            cout<<"Pair #"<<count++<<": Love is not all you need!"<<endl;
        }
    }
}