#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int cache[10001];
int arr[100];
int main(void)
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= K; ++i)
		cache[i] = 10001;

	for (int i = 0; i < N; ++i)
	{
		for (int j = arr[i]; j <= K;  ++j)
		{
			cache[j] = min(cache[j],1 + cache[j - arr[i]]);
		}
	}
	if (cache[K] == 10001)
		cout << -1 << '\n';
	else cout << cache[K] << '\n';
	
	return 0;
}