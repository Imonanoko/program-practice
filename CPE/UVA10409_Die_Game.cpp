#include <iostream>
using namespace std;
int main(void)
{
    int time;
    while (cin >> time)
    {
        int ary[6] = {1, 6, 4, 5, 3, 2};//[上,下,東,西,南,北]

        if (!time)
        {
            break;
        }
        while (time--)
        {
            string dir;
            cin >> dir;
            int temp, temp1;
            if (dir == "north")//朝北的各方向
            {
                temp = ary[0];
                temp1 = ary[1];
                ary[0] = ary[3];
                ary[1] = ary[5];
                ary[3] = temp1;
                ary[5] = temp;
            }
            if (dir == "south")//朝南的各方向
            {
                temp = ary[0];
                temp1 = ary[1];
                ary[0] = ary[5];
                ary[1] = ary[3];
                ary[3] = temp;
                ary[5] = temp1;
            }
            if (dir == "west")//朝西的各方向
            {
                temp = ary[0];
                temp1 = ary[1];
                ary[0] = ary[2];
                ary[1] = ary[4];
                ary[2] = temp1;
                ary[4] = temp;
            }
            if (dir == "east")////朝東的各方向
            {
                temp = ary[0];
                temp1 = ary[1];
                ary[0] = ary[4];
                ary[1] = ary[2];
                ary[2] = temp;
                ary[4] = temp1;
            }
        }
        cout << ary[0] << endl;
    }
}