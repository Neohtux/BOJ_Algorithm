#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N, M;


vector<int> pre_processing(string s);
vector<int> kmp(string s, string t);

vector<int> kmp(string s, string t)
{
	vector<int> ans;

	vector<int> fail = pre_processing(t);

	int j = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		while (j > 0 && s[i] != t[j]) j = fail[j - 1];

		if (s[i] == t[j])
		{
			if (j == t.size() - 1)
			{
				ans.push_back(i - j + 1);
				j = fail[j];
			}
			else j += 1;
		}
		
	}

	return ans;
}
int main(void)
{
	cin >> N >> M;
	int cnt = 0;
	string p;
	while (1)
	{
		p += 'I';
		if (cnt == N) break;
		p += 'O'; 
		cnt += 1;
	}
	
	string s;
	for (int i = 0; i < 13; ++i)
	{
		char ch;
		cin >> ch;
		s += ch;
	}
	vector<int> ans = kmp(s, p);

	cout << ans.size() << '\n';

	return 0;
}

vector<int> pre_processing(string s)
{
	vector<int> fail(s.size());

	int j = 0;
	fail[0] = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = fail[j - 1];
		}

		if (s[i] == s[j])
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