#include<iostream>
#include<algorithm>
using namespace std;
int N;

int cache[100000]; 
int arr[100000];

int go(int idx)
{
	if (idx == N - 1)
	{
		cache[idx] = arr[idx];
		return arr[idx];
	}

	int& ret = cache[idx];

	ret = max(arr[idx], arr[idx] + go(idx+1));

	return ret;
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	go(0);
	int ans = -100 * 100000 - 1;
	for (int i = 0; i < N; ++i)
	{
		if (ans < cache[i])
			ans = cache[i];
	}
	cout << ans << '\n';
	return 0;
}