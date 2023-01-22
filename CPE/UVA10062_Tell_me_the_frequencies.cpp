#include <iostream>
#include <algorithm>
using namespace std;
struct ascii
{
    int asciicode;
    int count;
};
bool compare(ascii a, ascii b)
{
    if (a.count < b.count)
        return true;
    else if(a.count == b.count){
        if(a.asciicode<b.asciicode){
            return false;
        }
        return true;
    }
    return false;
}

int main(void)
{
    string word;
    int det = 0;
    while (getline(cin, word))
    {
        if(det){
            cout<<endl;
        }
        det = 1;
        ascii ary[129];
        int index = 0;
        for (int j = 0; j < 129; j++)
        {
            ary[j].asciicode = j;
            ary[j].count = 0;
        }
        for (int i = 0; i < word.length(); i++)
        {
            if (!ary[word[i]].count)
            {
                index++;
                ary[word[i]].count++;
            }
            else
            {
                ary[word[i]].count++;
            }
        }
        sort(ary,ary+129,compare);
        for(int i = 128-index+1;i<129;i++){
            cout<<ary[i].asciicode<<" "<<ary[i].count<<endl;
        }
    }
}