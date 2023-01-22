#include <iostream>
using namespace std;
struct alpha
{
    char word;
    int count;
};
int main(void)
{
    string line1, line2;
    while (getline(cin, line1) && getline(cin, line2))
    {
        alpha line1word[26];
        alpha line2word[26];
        for (int i = 0; i < 26; i++)
        {
            line1word[i].word = 'a' + i;
            line1word[i].count = 0;
            line2word[i].word = 'a' + i;
            line2word[i].count = 0;
        }
        for (int i = 0; i < line1.length(); i++)
        {
            line1word[line1[i] - 'a'].count++;
        }
        for (int i = 0; i < line2.length(); i++)
        {
            line2word[line2[i] - 'a'].count++;
        }
        string ans = "";
        for (int i = 0; i < 26; i++)
        {
            int mintime = min(line1word[i].count, line2word[i].count);
            for (int j = 0; j < mintime; j++)
            {
                ans += line1word[i].word;
            }
        }
        cout << ans << endl;
    }
}