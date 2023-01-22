#include<iostream>
#include<string>
using namespace std;
string decToHex(int a){
    int mod;
    string c="",b;
    while(a!=0){
        mod=a%16;
        a/=16;
        b=to_string(mod);
        if(b=="10"){
            c="A"+c;
        }
        else if(b=="11"){
            c="B"+c;
        }
        else if(b=="12"){
            c="C"+c;
        }
        else if(b=="13"){
            c="D"+c;
        }
        else if(b=="14"){
            c="E"+c;
        }
        else if(b=="15"){
            c="F"+c;
        }
        else{
            c=b+c;
        }
    }
    return c;
}
int main(void){
    int dec;
    cout<<"Enter a dec:";
    cin>>dec;
    cout<<"dectohex:"<<decToHex(dec)<<endl;
}