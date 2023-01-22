#include<iostream>
using namespace std;
int main(void){
    int even=0;
    for(int i=1;i<101;i++){
        if (i%2==0){
            even+=i;
            continue;
        }
        continue;
    }
    cout<<even;
}