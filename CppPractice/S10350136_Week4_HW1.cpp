#include<iostream>
using namespace std;
int main(void){
    cout<<"叫块20俱计";
    int a,even=0,odd=0;
    for (int i=0;i<20;i++){
        cin>>a;
        if (a%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout<<"案计Τ"<<even<<""<<endl<<"计Τ"<<odd<<"";
}