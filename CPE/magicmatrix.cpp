#include<iostream>
using namespace std;
int main(void){
    int s,index;
    cin>>s;
    index=1;
    int ary[s+1][s+1],save;
    bool det[s][s]={0},det1=1,det2=1,det3=1;
    int i=0,j=s/2,num=1;
    while(true){
        if(index==s*s+1){
            break;
        }
        while(det[i][j]||i<0||j<0||i>=s||j>=s){
            if(0<=i&&i<s&&0<=i&&i<s&&det1&&det2&&det3){
                i--;
                j--;
                det1=0;
            }
            else if((i<0||j<0)&&det2&&det3){
                save=i;
                i=s-1;
                det2=0;
            }
            else if((i<0||j<0)&&det3){
                if(!det2){
                i=save;}
                save=j;
                j=s-1;
                det3=0;
            }
            else{
                if(!det3){
                    j=save;
                }
                i+=2;
                j+=1;
                det1=1;
                det2=1;
                det3=1;
            }
        }
        ary[i][j]=num++;
        det[i][j]=1;
        index++;
        det1=1;
        det2=1;
        det3=1;
        // cout<<i<<" "<<j<<" "<<ary[i][j]<<endl;
    }
    for(int k=0;k<s;k++){
        for(int m=0;m<s;m++){
            cout<<ary[k][m]<<" ";
        }
        cout<<endl;
    }
}