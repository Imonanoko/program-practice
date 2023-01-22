#include<iostream>
#include<cmath>
using namespace std;
int abso(int);
class Rectangle{
public:
    Rectangle(int,int,int,int);
    void setX1andY1(int,int);
    void setX2andY2(int,int);
    int getX1();
    int getX2();
    int getY1();
    int getY2();
    int getWidth();
    int getHeight();
    double getArea();
    double getPerimeter();
private:
    int x2,y2,x1,y1;
    int width;
    int height;
};
Rectangle::Rectangle(int a,int b,int c,int d){
    x1=a;
    y1=b;
    x2=c;
    y2=d;
}
void Rectangle::setX1andY1(int a,int b){
    x1=a;
    y1=b;
}
void Rectangle::setX2andY2(int a,int b){
    x2=a;
    y2=b;
}
int Rectangle::getX1(){
    return x1;
}
int Rectangle::getY1(){
    return y1;
}
int Rectangle::getX2(){
    return x2;
}
int Rectangle::getY2(){
    return y2;
}
int Rectangle::getWidth(){
    return (min(abso(x2-x1),abso(y2-y1)));
}
int Rectangle::getHeight(){
    return (max(abso(x2-x1),abso(y2-y1)));
}
double Rectangle::getArea(){
    width=min(abso(x2-x1),abso(y2-y1));
    height=max(abso(x2-x1),abso(y2-y1));
    return width*height;
}
double Rectangle::getPerimeter(){
    width=min(abso(x2-x1),abso(y2-y1));
    height=max(abso(x2-x1),abso(y2-y1));
    return 2*(width+height);
}


int main(void){
    cout<<"count rectangle"<<endl;
    cout<<"set rectangle(x1,y1,x2,y2):";
    int x11,x22,y11,y22;
    cin>>x11>>y11>>x22>>y22;
    Rectangle test(x11,y11,x22,y22);
    cout<<"getX1: "<<test.getX1()<<", "<<"gety1: "<<test.getY1()<<endl;
    cout<<"gety2: "<<test.getX2()<<", "<<"gety2: "<<test.getY2()<<endl;
    cout<<"getWidth: "<<test.getWidth()<<endl;
    cout<<"getHeight: "<<test.getHeight()<<endl;
    cout<<"getArea: "<<test.getArea()<<endl;
    cout<<"getPerimeter: "<<test.getPerimeter()<<endl;
}
int abso(int a){
    if(a>=0){return a;}
    return -a;
}