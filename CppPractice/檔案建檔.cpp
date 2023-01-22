#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main(void){
    ofstream outfile;
    outfile.open("score.txt");
    outfile<<right<<setw(5)<<"Mary"<<setw(6)<<30<<setw(3)<<20<<setw(3)<<54<<endl;
    outfile<<right<<setw(5)<<"Joe"<<setw(6)<<58<<setw(3)<<62<<setw(3)<<75<<endl;
    outfile<<right<<setw(5)<<"Kile"<<setw(6)<<65<<setw(3)<<98<<setw(3)<<78<<endl;
    outfile<<right<<setw(5)<<"Frank"<<setw(6)<<18<<setw(3)<<43<<setw(3)<<69<<endl;
    outfile<<right<<setw(5)<<"Gray"<<setw(6)<<61<<setw(3)<<58<<setw(3)<<78<<endl;
    outfile.close();
}