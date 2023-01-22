#include<iostream>
using namespace std;
bool det(int a,int b){
    while(a%b==0||a==1){
        if(a==1){
            return true;
        }
        else{
            a/=b;
        }
    }
    return false;
}
int main(void){
    int a,b;
    while ((cin>>a>>b))
    {
        if(b==1){
            cout<<"Boring!"<<endl;
        }
        else if(det(a,b)){
            cout<<a;
            while(a/b>0){
                a/=b;
                cout<<" "<<a;
            }
            cout<<endl;
        }
        else{
            cout<<"Boring!"<<endl;
        }
    }
    
}