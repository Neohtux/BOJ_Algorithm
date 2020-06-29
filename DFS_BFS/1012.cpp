//그래프 만들기
//그래프 전체 탐색하면서 , 배추가 위치해있는곳이 있다면
// 배추가 있는부분부터 DFS / BFS 탐색 
// 흰지렁이가 최소 몇개나 필요한지
// 행렬에서 각 연결요소가 몇개인지 ? 

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int arr[50][50];
int check[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int T, N, M ,K;
void dfs(int x, int y, int worm);
void bfs(int x, int y, int worm, queue<pair<int, int>> &q);
int main(void)
{
	cin >> T;
	

	while (T--)
	{
		cin >> M >> N >> K;
		int x, y;
		// 배추 심어져 있는곳? 배추심기...
		for (int i = 0; i < K; ++i)
		{
			cin >> x >> y;
			arr[y][x] = -1;
		}

		int worm = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] == -1) //배추 있는지 확인
				{
					if (check[i][j]==0)
					{
						q.push(make_pair(i, j));
						worm += 1;
						//dfs(i, j, worm);
						bfs(i, j, worm,q);
					}
				}
			}
		}
		
		cout << worm << '\n';
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));

	}
	return 0;
}


void bfs(int x, int y, int worm , queue<pair<int,int>> &q)
{
	check[x][y] = worm;
	
	//최초 한개 들어온 Queue
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); //큐가 비어있음;
		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];

			/*if (xn < 0 || xn >= N || yn < 0 || yn >= M)
				continue;*/
			if (xn >= 0 && xn < N && yn >= 0 && yn < M)
			{
				if (arr[xn][yn]==-1)
				{
					if (check[xn][yn] == 0)
					{
						check[xn][yn] = worm;
						q.push(make_pair(xn, yn));
					}
				}
			}
		}
	}
}
void dfs(int x, int y, int worm)
{
	check[x][y] = worm;

	for (int i = 0; i < 4; ++i)
	{
		int xn = x + dx[i];
		int yn = y + dy[i];

		//범위 설정
		if (xn < 0 || xn >= N || yn < 0 || yn >= M)
			continue;

		if (arr[xn][yn] == -1)
		{
			if (check[xn][yn] == 0)
			{
				dfs(xn, yn, worm);
			}
		}

	}
}