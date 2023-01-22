#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct Point {
    int x;
    int y;
};
void get_point(Point *);
double length(Point,Point);
Point get_mid(Point,Point);
int main(void){
    Point p1,p2,midp;
    double len;
    cout<<"Input first point:\n";
    get_point(&p1);
    cout<<"Input second point:\n";
    get_point(&p2);
    len=length(p1,p2);
    midp=get_mid(p1,p2);
    cout<<"\n\nPOINT #1("<<p1.x<<","<<p1.y<<")"<<endl;
    cout<<"\nPOINT #2("<<p2.x<<","<<p2.y<<")"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"\n    Length = "<<len<<endl;
    cout<<"      Midpoint: ("<<midp.x<<", "<<midp.y<<")"<<endl;
}
void get_point(Point *point){
    cout<<"    X-axis";
    cin>>point->x;                //(*point).x and point->x is same.
    cout<<"    Y-axis";
    cin>>point->y;
}
double length(Point p1,Point p2){
    double leng;
    int x_dif,y_dif;
    x_dif=(p1.x-p2.x);
    y_dif=(p1.y-p2.y);
    leng=sqrt((x_dif*x_dif+y_dif*y_dif));
    return leng;
}
Point get_mid(Point p1,Point p2){
    Point mid;
    mid.x=(p1.x+p2.x)/2;
    mid.y=(p1.y+p2.y)/2;
    return mid;
}