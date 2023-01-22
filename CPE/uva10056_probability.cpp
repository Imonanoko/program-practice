#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main(void){
    int time ;
    cin>>time;
    while(time--){
        int N,I;
        double P,r,a1,ans;
        cin>>N>>P>>I;
        if(P==0){
            cout<<0.0000<<endl;
        }
        else{
        r=pow((1-P),N);
        a1=P*pow((1-P),I-1);
        ans=a1/(1-r);
        cout<< setprecision(4) << fixed <<ans<<endl;}
    }
}