#include <iostream>
using namespace std;
int find(int);
int main(){
    int a,b,y,x;
    while(cin>>a>>b){
        int mx=0;
        if (a>b){
            x=a;
            y=b;
            }
        else{
            x=b;
            y=a;
        }
        for (int i=y;i<(x+1);i++){
            int test=find(i);
            if (mx<test ){mx=test;}
        }
        cout<<a<<" "<<b<<" "<<mx<<endl;
    }
}
int find(int x){
    int num=1;
    while (x!=1){
        if (x%2==1){
            x=3*x+1;
            num++;
        }
        else{
            x/=2;
            num++;
        }
    }
    return num;
}