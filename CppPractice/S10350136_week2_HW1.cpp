#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(void){
    string A, B, C;
    float a,b,c;
    cout<<"請輸入第一個科目名稱和成績";
    cin>>A>>a;
    cout<<"請輸入第二個科目名稱和成績:";
    cin>>B>>b;
    cout<<"請輸入第三個科目名稱和成績:";
    cin>>C>>c;
    cout<<fixed<<setprecision(1);
    cout<<left<<setw(15)<<A<<right<<setw(5)<<a<<endl;
    cout<<left<<setw(15)<<B<<right<<setw(5)<<b<<endl;
    cout<<left<<setw(15)<<C<<right<<setw(5)<<c<<endl;
}