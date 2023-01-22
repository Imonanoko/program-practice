#include<iostream>
using namespace std;
int main(void){
    int time,test=1;
    cin>>time;
    while(time--){
        int size,det=1,det1=1,det3=0;
        string trash1,trash2;
        cin>>trash1>>trash2;
        cin>>size;
        int ary[size*size];
        for(int i=0;i<size*size;i++){
            int M;
            cin>>M;
            ary[i]=M;
        }
        if(det){
            for(int i=0;i<(size*size);i++){
                if(ary[i]!=ary[size*size-i-1]||ary[i]<0){
                    det1=0;
                    break;
                }
                else{
                    continue;
                }
            }
            if(det1){
                cout<<"Test #"<<test<<": Symmetric."<<endl;
                test++;
            }
            else{
                cout<<"Test #"<<test<<": Non-symmetric."<<endl;
                test++;
            }
        }
    }
}