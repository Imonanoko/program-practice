#include<iostream>
using namespace std;
int main(void){
    int a,b,carry=0;
    cout<<"請輸入有幾個數據";
    cin>>a;
    int ary [a];
    for (int i=0;i<a;i++){
        cin>>b;
        ary[i]=b;
    }
    for(int i=0;i<a;i++){
        for (int j=0;j<a;j++){
           if (ary[j]>ary[j+1]){
                carry =ary[j];
                ary[j]=ary[j+1];
                ary[j+1]=carry;
           } 
        }
        cout<<"第"<<i+1<<"次";
        for (int num=0;num<a;num++){
            cout<<ary[num]<<" ";
        }
        cout<<endl;
    }
}