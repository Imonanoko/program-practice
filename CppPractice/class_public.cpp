#include<iostream>
#include<fstream>
using namespace std;
class test{
public:
    int i=0;
    string str="";
    test(int ,string);
    int geti();
    string getstr();
};
test::test(int i1,string str1){
    i=i1;
    str=str1;
}
int test::geti(){
    return i;
}
string test::getstr(){
    return str;
}
int main(void){
    test T(2,"willy");
    T.i=4;
    T.str=" ";
    cout<<T.geti()<<" "<<T.getstr();
}