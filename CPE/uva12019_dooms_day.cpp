#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <sstream>
using namespace std;
// 1/1 Saturday
// string array_str[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
void datadet(int M,int D)
{   
    string ary[7]={"Friday", "Saturday", "Sunday","Monday", "Tuesday", "Wednesday", "Thursday"};
    int totalday;
    switch (M)
    {
    case 1:
        totalday=D;
        break;
    case 2:
        totalday=31+D;
        break;
    case 3:
        totalday=31+D+28;
        break;
    case 4:
        totalday=31+D+28+31;
        break;
    case 5:
        totalday=31+D+28+31+30;
        break;
    case 6:
        totalday=31+D+28+31+30+31;
        break;
    case 7:
        totalday=31+D+28+31+30+31+30;
        break;
    case 8:
        totalday=31+D+28+31+30+31+30+31;
        break;
    case 9:
        totalday=31+D+28+31+30+31+30+31+31;
        break;
    case 10:
        totalday=31+D+28+31+30+31+30+31+31+30;
        break;
    case 11:
        totalday=31+D+28+31+30+31+30+31+31+30+31;
        break;
    case 12:
        totalday=31+D+28+31+30+31+30+31+31+30+31+30;
        break;
    }
    int day = totalday%7;
    cout<<ary[day]<<endl;
}
int main(void)
{
    int time;
    cin>>time;
    while(time--){
        int M,D;
        cin>>M>>D;
        datadet(M,D);
    }
}