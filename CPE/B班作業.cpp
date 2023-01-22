#include<iostream>
#include<sstream>
using namespace std;
int getDigit(int);
int sumOfDoubleEvenPlace(const string& cardnumber);
int sumOfOddPlace(const string& cardNumber);
bool startsWith(const string& cardNumber);
bool isVaild(const string & cardNumber){
    int sumeven=sumOfDoubleEvenPlace(cardNumber),sumodd=sumOfOddPlace(cardNumber);
    int mod=(sumeven+sumodd)%10;
    if(startsWith(cardNumber)&&mod==0){return 1;}
    return 0;
}
int sumOfDoubleEvenPlace(const string& cardNumber){
    long long s=0,num;
    stringstream ss;
    ss<<cardNumber;
    ss>>num;
    while(num!=0){
        int twice1;
        twice1=((num%100)/10)*2;
        s+=getDigit(twice1);
        num/=100;
    }
    return s;
}
int getDigit(int number){
    if(number<10){
        return number;
    }
    else{return(1+(number%10));}
}
int sumOfOddPlace(const string& cardNumber){
    long long s=0,num;
    stringstream ss;
    ss<<cardNumber;
    ss>>num;
    while(num!=0){
        s+=num%10;
        num/=100;
    }
    return s;

}
bool startsWith(const string& cardNumber){
    char num=cardNumber[0];
    int len=cardNumber.length();
    if(len<13||len>16){return 0;}
    if(num=='4'||num=='5'||num=='6'){return 1;}
    else if(num=='3'&&cardNumber[1]=='7'){return 1;}
    else{return 0;}

}
int main(void){
    string cardNumber;
    cin>>cardNumber;
    if(isVaild(cardNumber)){cout<<"Valid password"<<endl;}
    else{cout<<"Invaild password"<<endl;}
}