
#include <iostream>
#include <sstream>
using namespace std;
bool isinverse(int a)
{
	string str = to_string(a);
	int len = str.length();
	if (len % 2)
	{
		for (int i = 0; i < len / 2; i++)
		{
			if (str[i] != str[len - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
int afteradd(int a)
{
	string str=to_string(a),ans="";
	for(int i=str.length()-1;i>=0;i--){
		ans+=str[i];
	}
	stringstream ss;
	int b;
	ss<<ans;
	ss>>b;
	return a+b;
}
int main(void)
{
	int times, test,b=0;
	cin >> times;
	while (times--)
	{
		cin >> test;
		int add = test;
		int count = 0;
		if(isinverse(add)){
			add=afteradd(add);
			count++;
		}
		while (!isinverse(add))
		{
			count++;
			add=afteradd(add);
		}
		cout << count << ' ' << add<< endl;
	}
}