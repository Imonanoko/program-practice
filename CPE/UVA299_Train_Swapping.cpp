#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    int time ;
    cin>>time;
    
    while (time--)
    {
        int size,temp,count=0;
        cin>>size;
        int ary[size];
        for(int i = 0;i<size;i++){
            cin>>ary[i];
        }
        for(int i = size-1 ; i>=0;i--){
            for(int j =0;j<i;j++){
                if(ary[j]>ary[j+1]){
                    temp=ary[j];
                    ary[j]=ary[j+1];
                    ary[j+1]=temp;
                    count++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }
    
}