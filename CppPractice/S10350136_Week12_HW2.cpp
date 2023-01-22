#include<iostream>
using namespace std;
#define PI 3.14159
class Cylinder{
public:
    Cylinder();
    void setCylinderHeight(int);
    void setCylinderRadius(int);
    int  getCylinderHeight();
    int getCylinderRadius();
    double getCylinderVolume();
    double getCylinderSurfaceArea();
private:
    int radius;
    int height;;
};
Cylinder::Cylinder(){
    radius=0;
    height=0;
}
void Cylinder::setCylinderHeight(int a){
    height=a;
}
void Cylinder::setCylinderRadius(int a){
    radius=a;
}
int Cylinder::getCylinderHeight(){
    return height;
}
int Cylinder::getCylinderRadius(){
    return radius;
}
double Cylinder::getCylinderVolume(){
    return PI*radius*radius*height;
}
double Cylinder::getCylinderSurfaceArea(){
    return 2*PI*radius*radius+2*PI*radius*height;
}
int main(void){
    Cylinder cylinder;
    cout<<"count cylinder"<<endl;
    cout<<"setCylinderHeight: ";
    int H,R;
    cin>>H;
    cylinder.setCylinderHeight(H);
    cout<<"setCylinderRadius: ";
    cin>>R;
    cylinder.setCylinderRadius(R);
    cout<<"getCylinderHeight: "<<cylinder.getCylinderHeight()<<", getCylinderRadius: "<<cylinder.getCylinderRadius()<<endl;
    cout<<"getCylinderVolume: "<<cylinder.getCylinderVolume()<<endl;
    cout<<"getCylinderSurfaceArea: "<<cylinder.getCylinderSurfaceArea();
}