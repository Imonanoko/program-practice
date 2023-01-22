#include<iostream>
using namespace std;
int Fibonaccimal(int ai){
    if(ai==0){return 1;}
    else if(ai==1){return 1;}
    else{
        return Fibonaccimal(ai-1)+Fibonaccimal(ai-2);
    }
}
int main(void){
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        string ans="";
        int dec,fib=1;
        cin>>dec;
        int answer=dec;
        while(Fibonaccimal(fib)<=dec){
            fib++;
        }
        for(int j=fib-1;j>0;j--){
            if(Fibonaccimal(j)<=dec){
                dec-=Fibonaccimal(j);
                ans+="1";
            }
            else{ans+="0";}
        }
        cout<<answer<<" = "<<ans<<" (fib)"<<endl;

    }
}