#include <iostream>
using namespace std;
class A
{
    public:
        A();
        A(int);
        virtual void x();
    private:
        int data;
};
A::A(int a)
{
    data = a;
}
class B :public A
{
    public:
        B();
        B(int);
    private:
        int data;
};
B::B(int a)
{
    data = a;
}
class C :public A
{
    public:
        C();
        C(int);
    private:
        int data;
};
C::C(int a)
{
    data = a;
}
void A::x()
{
    cout << this -> data << endl;
}
int main()
{
    A a(1);
    B b(2);
    C c(3);
    a.x();
    b.x();
    c.x();
    return 0;
}