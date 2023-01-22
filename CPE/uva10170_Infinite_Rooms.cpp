#include<iostream>
using namespace std;
int main(void){
    long long int D,S;
    while(cin>>S>>D){
        long long int total=0;
        while(total<D){
            total+=S++;
        }
        S--;
        cout<<S<<endl;
        
    }

}