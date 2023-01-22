#include <iostream>
using namespace std;
int main(void)
{
    string st = "``";
    string nd = "\'\'";
    string str;
    int det = 0;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '\"')
            {
                if (det)
                {
                    det = 0;
                    cout << nd;
                }
                else
                {
                    cout << st;
                    det = 1;
                }
            }
            else
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
}