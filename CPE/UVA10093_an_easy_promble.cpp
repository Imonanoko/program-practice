#include <iostream>
using namespace std;
//利用餘式定理去拆開會變成全部的位數相加在除進位-1
int minbase(string a)//判斷最小可以幾進位
{
    int maxbase = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '-'|| a[i] == '+')
        {
            continue;
        }
        else if (a[i] > maxbase)
        {
            maxbase = a[i];
        }
    }
    if (maxbase >= 97)//a-z的數字代表'a'-61
    {
        return maxbase - 61;
    }
    else if (maxbase >= 65)//a-z的數字代表'A'-55
    {
        return maxbase - 55;
    }
    return maxbase - '0';
}
int alladd(string num)//將全部的數字相加
{
    int total = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '-'||num[i] == '+')
        {
            continue;
        }
        else if (num[i] >= 97)//a-z的數字代表'a'-61
        {
            total += num[i] - 61;
        }
        else if (num[i] >= 65)//a-z的數字代表'A'-55
        {
            total += num[i] - 55;
        }
        else
        {
            total += num[i] - '0';
        }
    }
    return total;
}
int main(void)
{
    string num;
    while (cin >> num)
    {
        if (num == "0")
        {
            cout << 2 << endl;
        }
        else
        {
            int det = 1;
            for (int i = minbase(num); i < 62; i++)//判斷最小進位是否能整除
            {
                if (alladd(num) % i == 0)
                {
                    cout << i + 1 << endl;
                    det = 0;
                    break;
                }
            }
            if (det)
            {
                cout << "such number is impossible!" << endl;
            }
        }
    }
}