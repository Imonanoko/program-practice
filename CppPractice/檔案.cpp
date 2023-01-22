#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct scores
{
    string name;
    int chi;
    int eng;
    int math;
    int total;
    float ave;
};

int main(void){
    scores data[5];
    ifstream inFile;
    ofstream outFile;
    inFile.open("score.txt");
    for(int i=0;i<5;i++){
        inFile>>data[i].name>>data[i].chi>>data[i].eng>>data[i].math;
        data[i].total=data[i].chi+data[i].eng+data[i].math;
        data[i].ave=data[i].total/3.;
    }
    inFile.close();
    outFile.open("result.txt");
    outFile<<right<<setw(5)<<"Name"<<setw(5)<<"Chi"<<setw(5)<<"Eng"<<setw(5)<<"Math"<<setw(7)<<"total"<<setw(10)<<"Ave"<<endl;
    for(int i=0;i<5;i++){
        outFile<<right<<setw(5)<<data[i].name<<setw(5)<<data[i].chi
        <<setw(5)<<data[i].eng<<setw(5)<<data[i].math<<setw(7)<<data[i].total<<setw(10)<<fixed<<setprecision(2)<<data[i].ave<<endl;
    }
    outFile.close();

}