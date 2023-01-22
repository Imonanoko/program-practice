#include<iostream>
using namespace std;
int main(void){
    int time,casecounter=1;
    cin>>time;
    while(time--){
        int a,b;
        // cin.ignore();
        cin>>a>>b;
        int total=0,i=0;
        for(i=a;i<=b;i++){
            if(i%2==1){
                total+=i;
            }
        }
        cout<<"Case "<<casecounter<<": "<<total<<endl;
        casecounter++;
    }
}