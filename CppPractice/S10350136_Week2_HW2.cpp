#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 
int main(){
    int a = 1234, b = 12, c = 1234567;
    cout<<"Using width"<<endl;
    cout<<"123456789012345678901234567890"<<endl;
    cout<<setfill('%')<<right<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout<<setw(10)<<b<<setw(10)<<c<<setw(10)<<a<<endl;
    cout<<setw(10)<<c<<setw(10)<<a<<setw(10)<<b<<endl;
    cout<<endl;
    cout<<"Using left and width"<<endl;
    cout<<"123456789012345678901234567890"<<endl;
    cout<<setfill(' ')<<left<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout<<setw(10)<<b<<setw(10)<<c<<setw(10)<<a<<endl;
    cout<<setw(10)<<c<<setw(10)<<a<<setw(10)<<b<<endl;
}