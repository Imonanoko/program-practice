#include<iostream>
using namespace std;
int len(int);
int main (void){
    int A,B;
    while(cin>>A>>B){
        int num=0;
        for(int i=min(A,B);i<=max(A,B);i++){
            num=max(len(i),num);
        }
        cout<<A<<" "<<B<<" "<<num<<endl;
    }
} 
int len(int i){
    int leng=1;
    while(i!=1){
    if(i%2==0){
        i/=2;
    }
    else{
        i=3*i+1;
    }
    leng++;
    }
    return leng;
}