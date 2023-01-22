#include <iostream>
#include <sstream>
using namespace std;
bool isprime(int a)
{
    int i = 2;
    while (true)
    {
        if (a == 2)
        {
            return true;
        }
        else if (a % i != 0)
        {
            if (a / i <= i)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}
int main(void)
{
    int a;
    while (cin >> a)
    {
        if (isprime(a))
        {
            string b = to_string(a), inverse = "";
            for (int i = 0; i < b.length(); i++)
            {
                inverse = b[i] + inverse;
            }
            stringstream ss;
            ss << inverse;
            int c;
            ss >> c;
            ss.clear();
            ss.str();
            if (isprime(c) && to_string(a).length() != 1 && inverse != b)
            {
                cout << a << " is emirp." << endl;
            }
            else
            {
                cout << a << " is prime." << endl;
            }
        }
        else
        {
            cout << a << " is not prime." << endl;
        }
    }
}