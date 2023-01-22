#include<iostream>
using namespace std;
bool password(string a){
    int countnum=0;
    if(a.length()!=12){
        return 0;
    }
    for(int i=0;i<a.length();i++){
        char b=a[i];
        if(isalpha(b)){
            continue;
        }
        else if (isdigit(b)){
            countnum++;
        }
        else{
            return 0;
        }
    }
    if(countnum<3){
        return 0;
    }
    return 1;
    
}
int main(void){
    string x;
    cout<<"Enter a password:";
    cin>>x;
    if(password(x)){
        cout<<"It is vaild password.";
    }
    else{
        cout<<"It is invaild password.";
    }
}