#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int H,W,N;
vector<pair<int, int>> v;

bool check[100];
void go(int index, int cnt);
int ans = 0;

int main(void)
{
	cin >> H >> W;
	cin >> N;

	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	go(0, 0);
	cout << ans << '\n';
	return 0;
}
void go(int index, int cnt)
{
	if (cnt == 2)
	{
		int x1, y1, x2, y2;
		bool isSecond = false;
		for (int i = 0; i < N; ++i)
		{
			if (check[i])
			{
				if (isSecond == false)
				{
					x1 = v[i].first;
					y1 = v[i].second;
					isSecond = true;
				}
				else 
				{
					x2 = v[i].first;
					y2 = v[i].second;
				}
					
			}		
		}
		//스티커 붙이기
		//붙이는것이 가능한지 (가로 ,세로) swap
		//붙은 스티커의 넓이합
		//넓이 합이 최대값인지

		//스티커 붙이기 어떻게 붙일 것인가.
		// 2개의 스티커 가로세로 =2^2 (4가지)
		//ㅡㅣ ㅡㅡ ㅣㅣ ㅣㅡ 4가지
		//세로로 연속해서 붙이냐, 가로로 연속해서 붙이냐 (2가지)
		for (int q = 0; q < 2; ++q)
		{
			for (int w = 0; w < 2; ++w)
			{
				//세로로 붙일때
				if (x1+x2 <= H && max(y1, y2) <= W)
				{
					int sum = (x1 * y1) + (x2 * y2);
					if (ans < sum)
						ans = sum;
				}
				// 가로로 붙일때
				else if (max(x1,x2) <= H && y1 + y2 <= W)
				{
					int sum = (x1 * y1) + (x2 * y2); 
					if (ans < sum)
						ans = sum;
				}
				swap(x2, y2);
			}
			swap(x1, y1);
		}
		return;
	}

	for (int i = index; i < N; ++i)
	{
		if (check[i]==false)
		{
			check[i] = true;
			go(i+1, cnt + 1);
			check[i] = false;
		}
		
	}
}
