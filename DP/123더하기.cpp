#include<iostream>
#include<cstring>
using namespace std;

long long cache[11];
int N;

long long go(long long num)
{
	if (num == N)
		return 1;
	if (num > N)
		return 0;

	long long & ret = cache[num];
	if (ret != -1)
		return ret;

	ret = 0;
	for (long long i = 1; i <= 3; ++i)
		if (num + i <= N) ret += go(num + i);

	return ret;
}
int main(void)
{
	int tc = 0;
	cin >> tc;
	while (tc--)
	{
		long long num = 0;
		cin >> num;
		N = num;
		memset(cache, -1, sizeof(cache));
		cout << go(0) << '\n';
	}
	return 0;
}