#include <iostream>
#include<cstdlib>
using namespace std;
class Rational{    
    public:
    Rational(int numerator=1, int denominator=1);
    int getNumerator();
    int getDenominator();
    Rational operator+(Rational &r2);
    Rational operator-(Rational &r2);
    Rational operator*(Rational &r2);
    Rational operator/(Rational &r2);
    static int gcd(int, int);
private :
int numerator;
int denominator;
};
int Rational::getNumerator()
{
   return numerator;
}
int Rational::getDenominator()
{
    return denominator;
}
int Rational::gcd(int n, int d)
{
    int num1 = abs(n);
    int num2 = abs(d);
    int gcd = 1;
    for (int i = 1; i <= num1 && i <= num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
Rational::Rational(int numerator, int denominator)
{
    int factor = gcd(numerator, denominator);
    this->numerator = numerator / factor;
    this->denominator = denominator / factor;
}
Rational Rational::operator+(Rational &r2)
{
    int n = numerator * r2.denominator +denominator * r2.numerator;
    int d = denominator * r2.denominator;
    return Rational(n, d);
}
Rational Rational::operator-(Rational &r2)
{
    int n = numerator * r2.denominator -denominator * r2.numerator;
    int d = denominator * r2.denominator;
    return Rational(n, d);
    
}
Rational Rational::operator*(Rational &r2)
{
    int n = numerator * r2.numerator;
    int d = denominator * r2.denominator;
    return Rational(n, d);
    
}
Rational Rational::operator/(Rational &r2)
{
    int n = numerator * r2.denominator;
    int d = denominator * r2.numerator;
    return Rational(n, d);
    
}
int main()
{
    Rational ratObj1(1, 6);
    Rational ratObj2(1, 2);
     //兩個分數相加
    Rational addValue = ratObj1 + ratObj2;
    cout << ratObj1.getNumerator() << "/" << ratObj1.getDenominator() << " + " << ratObj2.getNumerator() << "/" << ratObj2.getDenominator() << " = ";
    cout << addValue.getNumerator() << "/" << addValue.getDenominator();
    cout << endl;
    //兩個分數相減
    Rational subtractValue = ratObj1 - ratObj2;
    cout << ratObj1.getNumerator() << "/" << ratObj1.getDenominator() << " - " << ratObj2.getNumerator() << "/" << ratObj2.getDenominator() << " = ";
    cout << subtractValue.getNumerator() << "/" << subtractValue.getDenominator();
    cout << endl;
    //兩個分數相乘
    Rational multiplyValue = ratObj1 * ratObj2;
    cout << ratObj1.getNumerator() << "/" << ratObj1.getDenominator() << " * " << ratObj2.getNumerator() << "/" << ratObj2.getDenominator() << " = ";
    cout << multiplyValue.getNumerator() << "/" << multiplyValue.getDenominator();
    cout << endl;
    //兩個分數相除
    Rational divideValue = ratObj1 / ratObj2;
    cout << ratObj1.getNumerator() << "/" << ratObj1.getDenominator() << " / " << ratObj2.getNumerator() << "/" << ratObj2.getDenominator() << " = ";
    cout << divideValue.getNumerator() << "/" << divideValue.getDenominator();
    cout << endl;
}