//안전 영역 구하기
/*#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue <pair<int, int>> q;

int arr[101][101];
int arr_2[101][101];
int check[101][101];
int N;
void bfs(int x, int y, int safe_zone);
int ans_max = 0;
int main(void)
{
	cin >> N;

	int T=0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			T = max(T, arr[i][j]);
		}
	}
	//입력
	for (int test_case = 0; test_case <= T; ++test_case)
	{
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				 arr_2[i][j] = arr[i][j];
			}
		}
		//비의 양에 따라 잠기는 영역 표시가 달라짐
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (arr_2[i][j] <= test_case)
					arr_2[i][j] = -1;
			}
		}

		int safe_zone = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (arr_2[i][j] != -1 && check[i][j] == 0)
				{
					safe_zone += 1;
					q.push(make_pair(i, j));
					check[i][j] = safe_zone;
					bfs(i, j, safe_zone);
				}
			}
		}
		if (ans_max < safe_zone )
			ans_max = safe_zone;

		memset(check, 0, sizeof(check));
	}
	

	cout << ans_max << '\n';
	return 0;
}
void bfs(int x, int y, int safe_zone)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];

			if (xn < 0 || xn >= N || yn < 0 || yn >= N) continue;

			if (check[xn][yn] == 0 && arr_2[xn][yn] != -1)
			{
				check[xn][yn] = safe_zone;
				q.push(make_pair(xn, yn));
			}
		}
	}
}*/