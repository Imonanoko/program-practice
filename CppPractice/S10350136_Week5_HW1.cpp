#include <iostream>
using namespace std;
float F(float,float);
int main(void){
    float x,y,c;
    cout<<"請輸入F(X,Y)的X and Y 以空格分開:";
    cin>>x>>y;
    if(x<0||y<0){
        cout<<F(x,y);
    }
    else{
        c=F(x-1,y)+F(x,y-1);
        cout<<c;
    }
}
float F(float x,float y){
    return (x-y);
}