#include<iostream>
using namespace std;

bool check[160001];
int N;
int main(void)
{
	cin >> N;

	for (int I = 0; I <= N; ++I)
	{
		for (int V = 0; V <= N; ++V)
		{
			for (int X = 0; X <= N; ++X)
			{
				if (I + V + X > N) break;
				int L = N - I - V - X;
				int sum = (I * 1) + (V * 5) + (X * 10) + (L * 50);
				check[sum] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 160000; ++i)
		if (check[i]) ans += 1;

	cout << ans << '\n';
	return 0;
}