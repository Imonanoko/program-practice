#include<iostream>
#include <algorithm>
using namespace std;
int isOdd(int);
bool compare(int ,int);
int M;
int main(void){
    int N;
    int arr[10001];
    while(cin>>N>>M){
        cout<<N<<" "<<M<<endl;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr,arr+N,compare);
        for(int i=0;i<N;i++){
            cout<<arr[i]<<endl;
        }
    }
}
int isOdd(int a){
    int mod=a%2;
    if(mod<0){mod+=2;}
    return mod;
}
bool compare(int a,int b){
    if(a%M!=b%M){return a%M<b%M;}
    if(isOdd(a)!=isOdd(b)){return isOdd(a);}
    if(isOdd(a)){return a>b;}
    return b>a;
}