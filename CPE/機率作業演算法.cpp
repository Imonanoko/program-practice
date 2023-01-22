#include<iostream>
#include<cmath>
using namespace std;
string tobinary(int a){
    string ans="";
    while(a/2!=0){
        ans+=to_string(a%2);
        a/=2;
    }
    ans="1"+ans;
    return ans;
}
string changmn(int a,int m,int n){
    string bin=tobinary(a),ans="";
    int time = m+n-bin.length(),total=0;
    if(bin.length()<m+n){
        for(int i=0;i<time;i++){
            bin="0"+bin;
        }
    }
    for(int j=0;j<(m+n);j++){
        if(bin[j]=='1'){
            total++;
        }   
    }
    if(total==m){
        for(int k=0;k<m+n;k++){
            if(bin[k]=='1'){
                ans+="m";
            }
            else{
                ans+="n";
            }
        }
        return ans;
    }
    return ans;
}
bool detpro(string a){
    int countn=0,countm=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='n'){
            countn++;
        }
        else{
            countm++;
        }
        if(countn>=countm){
            return true;
        }
    }
    return false;
}
int main(void){
    int m,n,count=0,ans1=0,ans2=0;
    cin>>m>>n;
    for(int i=0;i<pow(2,m+n);i++){
        string P=changmn(i,m,n);
        if(P!=""){
            cout<<P<<endl;
            count++;
            if(detpro(P)){
                ans1++;
            }
            else{
                ans2++;
            }
        } 
    }
    cout<<"first problem:"<<ans1<<"/"<<count<<endl;
    cout<<"second problem:"<<ans2<<"/"<<count<<endl;
}