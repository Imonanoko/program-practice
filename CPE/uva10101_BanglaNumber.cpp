#include <iostream>
#include <iomanip>
using namespace std;
//以10000000為一組看
void outcome(long long int a){
    if(a/10000000!=0){
        outcome(a/10000000);
        cout<<" kuti";
        a%=10000000;
    }
    if(a/100000!=0){
        outcome(a/100000);
        cout<<" lakh";
        a%=100000;
    }
    if(a/1000!=0){
        outcome(a/1000);
        cout<<" hajar";
        a%=1000;
    }
    if(a/100!=0){
        outcome(a/100);
        cout<<" shata";
        a%=100;
    }
    if(a!=0){
        cout<<" "<<a;
    }
}
int main(void){
    long long int a,count=1;
    while(cin>>a){
        cout<<setw(4)<<count<<".";
        outcome(a);
        count++;
        if(a==0){cout<<" 0";}
        cout<<endl;
    }
}