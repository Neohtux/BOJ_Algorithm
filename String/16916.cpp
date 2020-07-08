#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<pair<int, int>> kmp(string t, string s);
vector<int> pre_processing(string str);

int main(void)
{
	int a = 'a';
	int A = 'A';

	string s, t;
	cin >> s >> t;

	/*for (int i = 0; i < s.size(); ++i)
	if (s[i] < 97) s[i] += 32;
	for (int i = 0; i < s.size(); ++i)
	if (t[i] < 97) t[i] += 32;*/

	//cin >> s;

	vector<pair<int, int>> ans;
	//a = pre_processing(s);
	ans = kmp(t, s);

	if (ans.size() == 0)
	{
		cout << "0" << '\n';
	}
	else
	{
		cout << "1" << '\n';
	}

	return 0;
}
vector<pair<int, int>> kmp(string t, string s)
{
	vector<int> fail = pre_processing(t);

	vector<pair<int, int>> ans;
	int j = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		while (j > 0 && t[j] != s[i])
		{
			j = fail[j - 1];
		}

		if (t[j] == s[i])
		{
			if (j == t.size() - 1) //있는경우 부분 문자열이
			{
				ans.push_back(make_pair(i - j + 1, t.size()));
				j = fail[j];
			}
			else
			{
				j += 1;
			}
		}
	}

	return ans;
}
vector<int> pre_processing(string str)
{
	int size = str.length();
	vector<int> fail(size);

	int j = 0;
	fail[0] = 0;
	for (int i = 1; i < size; ++i)
	{
		while (j > 0 && str[i] != str[j])
		{
			j = fail[j - 1];
		}

		//str의 i번째 문자와 j번째 문자가 같은경우
		//접두사 == 접미사 갯수 
		if (str[i] == str[j])
		{
			fail[i] = j + 1;
			j += 1;
		}
		else
		{
			fail[i] = 0;
		}
	}

	return fail;
}