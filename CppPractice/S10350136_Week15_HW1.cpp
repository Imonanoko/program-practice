#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.14159

class Point {
public:
    Point();
    void setX1andY1(int ,int);
    int getX1();
    int getY1();
protected:
    int x1,y1;
};
Point::Point(){
    x1=0;
    y1=0;
}
void Point::setX1andY1(int x,int y){
    x1=x;
    y1=y;
}
int Point::getX1(){
    return x1;
}
int Point::getY1(){
    return y1;
}

class Circle: public Point{
public:
    Circle();
    void setRadius(int);
    int getRadius();
    double getArea();
    double getPerimeter();
private:
    int radius;
};
Circle::Circle(){
    radius=1;
}
void Circle::setRadius(int r){
    radius=r;
}
int Circle::getRadius(){
    return radius;
}
double Circle::getArea(){
    return PI*radius*radius;
}
double Circle::getPerimeter(){
    return 2*PI*radius;
}
class Rectangle: public Point
{
private:
    int x2,y2;
    int width;
    int height;
public:
    Rectangle();
    void getX1andY1();
    void setX2andY2(int ,int);
    int getWidth();
    int getHeight();
    double getArea();
    double getPerimeter();
    int getX2();
    int getY2();
};
Rectangle::Rectangle(){
    x2=1;
    y2=1;
}
void Rectangle::getX1andY1(){
    cout<<"("<<x1<<", "<<y1<<")";
}
void Rectangle::setX2andY2(int x,int y){
    x2=x;
    y2=y;
}
int Rectangle::getWidth(){
    width=abs(x2-x1);
    return width;
}
int Rectangle::getHeight(){
    height=abs(y2-y1);
    return height;
}
double Rectangle::getArea(){
    return width*height;
}
double Rectangle::getPerimeter(){
    return 2*(width+height);
}
int Rectangle::getX2(){
    return x2;
}
int Rectangle::getY2(){
    return y2;
}
int main(void){
    Point pointObj;
    cout<<fixed<<setprecision(2);
    cout<<"��¦���O���I�y�Ь�: ("<<pointObj.getX1()<<", "<<pointObj.getY1()<<")"<<endl;
    cout<<"-------------------------------------------"<<endl;
    Circle circleObj;
    cout<<"��߮y�Ь�: "<<"("<<circleObj.getX1()<<", "<<circleObj.getY1()<<")"<<endl;
    cout<<"��b�|:"<<circleObj.getRadius()<<endl<<endl;
    circleObj.setX1andY1(1,1);
    circleObj.setRadius(3);
    cout<<"��߮y�Чאּ:"<<"("<<circleObj.getX1()<<", "<<circleObj.getY1()<<")"<<endl;
    cout<<"���אּ�b�|:"<<circleObj.getRadius()<<endl<<endl;
    cout<<"��έ��n:"<<circleObj.getArea()<<endl;
    cout<<"��ΩP��:"<<circleObj.getPerimeter()<<endl;
    cout<<"-------------------------------------------"<<endl;
    Rectangle rectObj;
    cout<<"����Ψ��I�y�Ь�:";
    rectObj.getX1andY1();
    cout<<", ("<<rectObj.getX2()<<", "<<rectObj.getY2()<<")"<<endl;
    cout<<"����Ϊ��e = "<<rectObj.getWidth()<<endl;
    cout<<"����Ϊ���? = "<<rectObj.getHeight()<<endl<<endl;
    rectObj.setX1andY1(2,2);
    rectObj.setX2andY2(5,6);
    cout<<"����Ψ��I�y�Ч��?:";
    rectObj.getX1andY1();
    cout<<", ("<<rectObj.getX2()<<", "<<rectObj.getY2()<<")"<<endl;
    cout<<"����Ϊ��e = "<<rectObj.getWidth()<<endl;
    cout<<"����Ϊ���? = "<<rectObj.getHeight()<<endl<<endl;
    cout<<"����έ��n = "<<rectObj.getArea()<<endl;
    cout<<"����Ϊ��P�� = "<<rectObj.getPerimeter()<<endl<<endl;
}


















