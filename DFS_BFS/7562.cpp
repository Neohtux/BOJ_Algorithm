#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int arr[301][301];
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };


void bfs(queue<pair<pair<int, int>, int>> &q);
int N;
int main(void)
{
	int T;
	cin >> T;

	int s_x, s_y;
	int d_x, d_y;

	queue<pair<pair<int, int>, int>> q;
	while (T--)
	{
		cin >> N;
		cin >> s_x >> s_y;
		cin >> d_x >> d_y;
		q.push(make_pair(make_pair(s_x, s_y),1));
		arr[s_x][s_y] = 1;

		bfs(q);
		cout << arr[d_x][d_y] - 1 << '\n';
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}
void bfs(queue<pair<pair<int, int>,int>> &q)
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];


			if (xn < 0 || xn >= N || yn < 0 || yn >= N) continue;

			if (arr[xn][yn] == 0)
			{
				arr[xn][yn] = dist + 1;
				q.push(make_pair(make_pair(xn, yn),dist+1));
			}
		}

	}
}