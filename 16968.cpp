#include<iostream>
#include<string>

using namespace std;

int go(string & str, int index, char before);
int main(void)
{
	string st;
	cin >> st;
	int ans = go(st, 0, '#');

	cout << ans << '\n';
	return 0;
}
int go(string & str, int index, char before)
{
	if (index == str.size())
		return 1;

	char start, end;
	if (str[index] == 'd')
	{
		start = '0';
		end = '9';
	}
	else
	{
		start = 'a';
		end = 'z';
	}
	int ans = 0;
	for (char i = start; i <= end; ++i)
	{
		if (i != before)
		{
			ans += go(str, index + 1, i);
		}
	}

	return ans;
}