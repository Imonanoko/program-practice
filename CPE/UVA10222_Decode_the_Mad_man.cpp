#include<iostream>
#include<string.h>
using namespace std;
int main(void){
    char password[1000];
    while(cin.getline(password,1000,'\n')){
    string str="";
    string stline="qwertyuiop[]\\";
    string ndline="asdfghjkl;\'";
    string rdline="zxcvbnm,./";
    string Bstline="QWERTYUIOP[]\\";
    string Bndline="ASDFGHJKL;\'";
    string Brdline="ZXCVBNM,./";
    for(int i=0;i<strlen(password);i++){
        for(int j=0;j<stline.length();j++){
            if(stline[j]==password[i]||Bstline[j]==password[i]){
                if(j>1){
                    str+=stline[j-2];
                }
                else if(j==1){str+="\\";}
                else if(j==0){str+="]";}
            }
        }
        for(int j=0;j<ndline.length();j++){
            if(ndline[j]==password[i]||Bndline[j]==password[i]){
                if(j>1){
                    str+=ndline[j-2];
                }
                else if(j==1){str+="\'";}
                else if(j==0){str+=";";}
            }
        }
        for(int j=0;j<rdline.length();j++){
            if(rdline[j]==password[i]||Brdline[j]==password[i]){
                if(j>1){
                    str+=rdline[j-2];
                }
                else if(j==1){str+="/";}
                else if(j==0){str+=".";}
            }
        }
        if(password[i]==' '){
            str+=password[i];
        }
    }
    cout<<str<<endl;
    }
}