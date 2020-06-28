#include<iostream>
#include<algorithm>
using namespace std;

int A, B, C, X, Y;
void solve();
int main(void)
{
	cin >> A >> B >> C >> X >> Y;

	solve();
	return 0;
}

void solve()
{
	int sum = 0;
	int ans = X * A + Y * B;
	for (int i = 1; i <= 100000; i++)
	{
		sum = (2 * C*i) + max(0, X - i)*A + (max(0, Y - i)*B);

		if (sum < ans)
			ans = sum;
	}
	cout << ans << '\n';
}