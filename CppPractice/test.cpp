#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class shape{
    public:
    shape();
    void setname(string);
    string getname();
    void setcolor(string);
    string getcolor();
    virtual double getarea();
    virtual double getperimeter();
    private:
    string name;
    string color;
};
shape::shape(){
    name="shape";
    color="blue";
}
void shape::setname(string name){
    this->name=name;
}
string shape::getname(){
    return name;
}
void shape::setcolor(string color){
    this->color=color;
}
string shape::getcolor(){
    return color;
}
double shape::getarea(){
    return 1.0;
}
double shape::getperimeter(){
    return 1.0;
}
class square:public shape{
    public:
    void setside(int);
    int getside();
    double getarea();
    double getperimeter();
    private:
    int side;
};
void square::setside(int side){
    this->side=side;
}
int square::getside(){
    return side;
}
double square::getarea(){
    return side*side;
}
double square::getperimeter(){
    return 4*side;
}
class righttriangle:public shape
{
    public:
    void setBottom(int);
    int getBottom();
    void setheight(int);
    int getheight();
    double getarea();
    double getperimeter();
    private:
    int bottom;
    int height;
};
void righttriangle::setBottom(int bottom){
    this->bottom=bottom;
}
int righttriangle::getBottom(){
    return bottom;
}
void righttriangle::setheight(int height){
    this->height=height;
}
int righttriangle::getheight(){
    return height;
}
double righttriangle::getarea(){
    return (bottom*height)/2;
}
double righttriangle::getperimeter(){
    return bottom+height+sqrt(bottom*bottom+height*height);
}
void information(shape &obj){
    cout<<"Area:"<<obj.getarea()<<endl;
    cout<<"Perimeter:"<<obj.getperimeter()<<endl;
}


int main(void){
    shape shapeobj;
    cout<<"name:"<<shapeobj.getname()<<endl;
    cout<<"color:"<<shapeobj.getcolor()<<endl;
    information(shapeobj);
    square squareobj;
    squareobj.setname("square");
    squareobj.setcolor("red");
    cout<<"name:"<<squareobj.getname()<<endl;
    cout<<"color:"<<squareobj.getcolor()<<endl;
    squareobj.setside(5);
    information(squareobj);
    righttriangle triangleobj;
    triangleobj.setname("right triangle");
    triangleobj.setcolor("green");
    triangleobj.setBottom(6);
    triangleobj.setheight(7);
    cout<<"name:"<<triangleobj.getname()<<endl;
    cout<<"color:"<<triangleobj.getcolor()<<endl;
    information(triangleobj);
}