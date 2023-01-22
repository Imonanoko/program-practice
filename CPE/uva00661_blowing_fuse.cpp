#include<iostream>
using namespace std;
int main(void){
    int n,m,c,Sequence=0;
    while(cin>>n>>m>>c){
        Sequence++;
        int total=0,ctrl=0,maxc=0;
        if(n==0&&m==0&&c==0){
            break;
        }
        int power[n][n];
        for(int i=0;i<n;i++){
            cin>>power[i][0];
            power[i][1]=0;
        }
        for(int i=0;i<m;i++){
            int open;
            cin>>open;
            if(!power[open-1][1]){
                power[open-1][1]=1;
                total+=power[open-1][0];
                maxc=max(maxc,total);
            }
            else{
                power[open-1][1]=0;
                total-=power[open-1][0];
            }
            if(total>c){
                ctrl=1;
            }
        }
        if(ctrl){
            cout<<"Sequence "<<Sequence<<endl;
            cout<<"Fuse was blown."<<endl<<endl;
        }
        else{
            cout<<"Sequence "<<Sequence<<endl;
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<maxc<<" amperes."<<endl<<endl;
        }
    }
}