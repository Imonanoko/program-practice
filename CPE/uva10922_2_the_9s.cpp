#include <iostream>
#include <algorithm>
using namespace std;
bool ismultipleof9(string a)
{
    int total = 0;
    for (int i = 0; i < a.length(); i++)
    {
        total += a[i] - '0';
    }
    if (total % 9 == 0)
    {
        return true;
    }
    return false;
}
int degree(string a)
{
    int count = 0;
    if(a=="9"){
        count++;
    }
    while (true)
    {
        int total = 0;
        for (int i = 0; i < a.length(); i++)
        {
            total += a[i] - '0';
        }
        if (total % 9 == 0 &&to_string(total)!=a)
        {
            a=to_string(total);
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
int main(void)
{
    string a;
    while (cin >> a && a != "0")
    {
        if (ismultipleof9(a))
        {
            cout << a << " is a multiple of 9 and has 9-degree " << degree(a) <<"."<< endl;
        }
        else
        {
            cout << a << " is not a multiple of 9." << endl;
        }
    }
}
