#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct manytree
{
    string tree;
    int count = 0;
};
bool compare(manytree a, manytree b)
{
    if (a.tree < b.tree)
    {
        return true;
    }
    return false;
}
int main(void)
{
    int time;
    string str, save;
    cin >> time;
    getline(cin, str);
    getline(cin, str);
    while (time--)
    {
        manytree ary[10001];
        int index = 0;
        int count = 0;
        int dis = 0;
        while (getline(cin, str))
        {
            if (str == "")
            {
                break;
            }
            if (index == 0)
            {
                ary[index].tree = str;
                ary[index].count++;
                index++;
                count++;
            }
            else
            {
                int det = 1;
                for (int i = 0; i < index; i++)
                {
                    if (str == ary[i].tree)
                    {
                        ary[i].count++;
                        count++;
                        det = 0;
                        if (count == 2)
                        {
                            save = str;
                        }
                    }
                }
                if (det)
                {
                    ary[index].tree = str;
                    index++;
                    ary[index].count++;
                    count++;
                    if (count == 2)
                    {
                        save = str;
                    }
                }
            }
        }
        int det1 = 1;
        for (int i = 0; i < index; i++)
        {
            if (save == ary[i].tree)
            {
                ary[i].count++;
                det1 = 0;
            }
        }
        if (det1)
        {
            ary[index].tree = save;
            index++;
            ary[index].count++;
        }
        sort(ary, ary + index, compare);
        for (int i = 0; i < index; i++)
        {
            float ans = (ary[i].count) * 100.0 / count;
            string ansstr = to_string(ans);
            cout << fixed << setprecision(4) << ary[i].tree << " " << ans << endl;
        }
        if (time)
        {
            cout << endl;
        }
    }
}