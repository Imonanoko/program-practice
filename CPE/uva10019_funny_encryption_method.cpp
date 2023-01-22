#include<iostream>
using namespace std;
string tobinary(int a){
    string ans="";
    while(a>0){
        int mod = a%2;
        ans=to_string(mod)+ans;
        a/=2;
    }
    return ans;
}
int main(void){
    int time;
    cin>>time;
    while(time--){
        int data;
        cin>>data;
        string bin=tobinary(data);
        int countbin=0;
        for(int i=0;i<bin.length();i++){
            if(bin[i]=='1'){
                countbin++;
            }
        }
        cout<<countbin<<" ";
        int howmany1=0;
        for(int j = 0;j<to_string(data).length();j++){
            char num=to_string(data)[j];
            if(num=='1'||num=='2'||num=='4'||num=='8'){
                howmany1++;
            }
            else if(num=='3'||num=='5'||num=='6'||num=='9'){
                howmany1+=2;
            }
            else if(num=='7'){
                howmany1+=3;
            }
        }
        cout<<howmany1<<endl;
    }
}