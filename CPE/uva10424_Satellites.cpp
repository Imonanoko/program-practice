#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(void){
    double s,a;
    string angle;
    while(cin>>s>>a>>angle){
        s+=6440;
        if(angle=="min"){
            a/=60.0;
        }
        double arc = 2*s*M_PI*a/360;
        double chord = sqrt(2*s*s-2*s*s*cos(a*M_PI/180));
        cout<<fixed<<setprecision(6)<<arc<<" "<<chord<<endl;
    }
}