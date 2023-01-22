#include <iostream>
using namespace std;
bool cort(int *stk, int index)
{
    int Case;
    for (int i = 1; i < index; i++)
    {
        Case=stk[i-1];
        if (Case > stk[i])
        {
            return true;
        }
    }
    return false;
}
void inverse(int *stk, int flip)
{
    int temp;
    for (int i = 0; i <= flip / 2; i++)
    {
        temp = stk[i];
        stk[i] = stk[flip - i];
        stk[flip - i] = temp;
    }
}
int main(void)
{
    int stk[31], index = 0;
    while (cin >> stk[index++])
    {
        while (cin >> stk[index++])
        {
            char br = getchar();
            if (br == '\n')
            {
                break;
            }
        }
        for (int i = 0; i < index; i++)
        {
            if (i == index - 1)
            {
                cout << stk[i] << endl;
            }
            else
            {
                cout << stk[i] << " ";
            }
        }
        int a = index;
        while (cort(stk, a))
        {
            int maxnum = 0, posi = 0;
            for (int i = 0; i < index; i++)
            {
                if (stk[i] > maxnum)
                {
                    maxnum = stk[i];
                    posi = i;
                }
            }
            if (posi == index - 1)
            {
                index--;
            }
            else if (posi == 0)
            {
                inverse(stk, --index);
                cout << a - index << " ";
            }
            else
            {
                inverse(stk, posi);
                cout << a - posi << " ";
                inverse(stk, --index);
                cout << a - index << " ";
            }
        }
        cout << 0 << endl;
        index = 0;
    }
}
