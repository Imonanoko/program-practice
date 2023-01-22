#include<iostream>
using namespace std;
int main(void){
    int a;
    cin>>a;
    while(a!=0){
        int square;
        square=(a*(a+1)*(2*a+1))/6;
        cout<<square<<endl;
        cin>>a;
    }
}