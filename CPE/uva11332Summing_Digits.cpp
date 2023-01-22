#include<iostream>
#include<sstream>
using namespace std;
string g(string digit){
    while(digit.length()!=1){//當字串長度不等於1的時候繼續
        int num=0;
        for(int i=0;i<digit.length();i++){//將每個位數獨立出來相加
            num+=digit[i]-'0';
        }
        digit=to_string(num);
    }
    return digit;
}

int main(void){
    string digit;
    while(cin>>digit){
        if (digit=="0"){break;}//輸入0時結束
        cout<<g(digit)<<endl;
    }
}