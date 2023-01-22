#include<iostream>
using namespace std;
int main(void){
    int time;
    cin>>time;
    while(time--){
        int day,meeting;
        cin>>day;
        int ary[day+1]={0};
        cin>>meeting;
        while (meeting--)
        {
            int a;
            cin>>a;
            for(int i = a;i<=day;i+=a){
                ary[i]=1;
            }
        }
        for(int i=0;i<=day;i++){
            if(i%7==6||i%7==0){
                ary[i]=0;
            }
        }
        int count=0;
        for(int i=0;i<=day;i++){
            if(ary[i]==1){
                count++;
            }
        }
        cout<<count<<endl;
        
    }
}