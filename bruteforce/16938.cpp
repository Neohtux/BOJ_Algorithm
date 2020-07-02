#include<iostream>
#include<vector>
using namespace std;

void go(int index, int cnt, int min, int max, int sum);
int N, L, R, X;

int check[15];
vector<int> v;
int ans;
int main(void)
{
	cin >> N >> L >> R >> X;
	int n = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> n;
		v.push_back(n);
	}
	go(0, 0, 1e9, 0, 0);
	cout << ans << '\n';
	return 0;
}
void go(int index, int cnt, int min, int max, int sum)
{
	if (index > N || sum > R)
		return;

	if (cnt >= 2 && max - min >= X && sum >= L && sum <= R)
	{
		ans += 1;
	}

	for (int i = index; i < N; ++i)
	{
		if (check[i] == false)
		{
			check[i] = true;

			if (cnt >= 1)
			{
				min = 1e9;
				max = 0;
				for (int k = 0; k < N; ++k)
				{
					if (check[k])
					{
						if (min > v[k])
							min = v[k];

						if (max < v[k])
							max = v[k];
					}
				}
			}
			go(i + 1, cnt + 1, min, max, sum + v[i]);
			check[i] = false;
		}
	}

}