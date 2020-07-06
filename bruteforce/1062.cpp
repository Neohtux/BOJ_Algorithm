#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check[26];
void go(int cnt, int index);
int N, K;
int ans = 0;
vector<string> word_list;
int main(void)
{
	cin >> N >> K;
	if (K < 5)
	{
		cout << 0 << '\n';
		return 0;
	}
	if (K == 26)
	{
		cout << N << '\n';
		return 0;
	}
	word_list.assign(N, "");
	for (int i = 0; i < N; ++i)
	{
		cin >> word_list[i];
		word_list[i].erase(word_list[i].begin(), word_list[i].begin() + 4);
		word_list[i].erase(word_list[i].end() - 4, word_list[i].end());
	}
	check['a' - 'a'] = check['n' - 'a'] = check['t' - 'a'] = check['i' - 'a'] = check['c' - 'a'] = true;

	K = K - 5;
	//go(0,0);
	
	cout << ans << '\n';
	return 0;
}
void go(int cnt, int index)
{
	if (cnt == K)
	{
		string temp;
		int can_read = 0;
		for (int i = 0; i < N; ++i)
		{
			temp = word_list[i];
			bool isRead = true;
			for (int j = 0; j < temp.size(); ++j) //r , c , h , e, l , l ,o , c , a , r
			{
				if (!check[temp[j]-'a']) //알파벳을 배우지 않은경우
				{
					isRead = false;
					break;
				}
			}
			if (isRead) 
				can_read += 1;
		}
		if (can_read > ans)
			ans = can_read;
		return;
	}

	//0~25 : a ~ z;
	for (int i = index; i < 26; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			go(cnt + 1,i+1);
			check[i] = false;
		}
	}

}