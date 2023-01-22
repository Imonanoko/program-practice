#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int size, time = 1;
    while (cin >> size)
    {
        int sequence[size], det = 1;
        for (int i = 0; i < size; i++)
        {
            cin >> sequence[i];
        }
        int afteradd[(size - 1) * (size) / 2];
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j <= size; j++)
            {
                afteradd[index++] = sequence[i] + sequence[j];
            }
        }
        sort(afteradd, afteradd + index);
        for (int i = 0; i <= index; i++)
        {
            if (afteradd[i] == afteradd[i + 1])
            {
                cout << "Case #" << time++ << ": It is not a B2-Sequence." << endl;
                det = 0;
                break;
            }
        }
        if (det)
            cout << "Case #" << time++ << ": It is a B2-Sequence." << endl;
        cout << endl;
    }
}