#include<iostream>
#include<fstream>
using namespace std;

class Student{
public:
    Student();
    Student(int,string,int);
    void display();
    int getid();
    string getName();
    int getScore();

private:
    int id;
    string name;
    int score;
};
Student::Student(){
    id=1;
    name="John";
    score=60;
}
Student::Student(int id2,string name2,int score2){
    id=id2;
    name=name2;
    score=score2;
}
void Student::display(){
    cout<<id<<" "<<name<<" "<<score<<endl;
}
int Student::getid(){
    return id;
}
string Student::getName(){
    return name;
}
int Student::getScore(){
    return score;
}

int main(void){
    fstream binaryIO;
    Student stu1;
    Student stu2(2,"Linda",92);
    Student stu3(3,"Bright",98);
    Student stu4(4,"Willy",60);
    Student stu5(5,"Jhon",57);
    stu1.display();
    stu2.display();
    stu3.display();
    stu4.display();
    stu5.display();
    binaryIO.open("classObj4.dat",ios::out|ios::binary);
    binaryIO.write(reinterpret_cast<char *>(&stu1),sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&stu2),sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&stu3),sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&stu4),sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&stu5),sizeof(Student));
    binaryIO.close();
    //read data from file
    Student studentData;
    cout<<"\nreading data..."<<endl;
    binaryIO.open("classObj4.dat",ios::in|ios::binary);
    while(binaryIO.read(reinterpret_cast<char *>(&studentData),sizeof(Student))){
        studentData.display();
    }
    binaryIO.close();
}