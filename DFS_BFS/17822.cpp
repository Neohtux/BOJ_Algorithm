#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int N, M, T;
int arr[55][55];
int check[55][55];
void rotate(int x, int dir, int n);
void bfs(queue<pair<int, int>> &q, int prev);
int ans;
bool flag = false;

int main(void)
{
	
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) // I/O 초기화
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}
	while (T--) //원판 회전
	{
		int x, dir, k;
		cin >> x >> dir >> k;
		rotate(x, dir, k); //원판 회전

		//check 배열 초기화
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				check[i][j] = false;
		}
		flag = false;
		//bfs 탐색
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] != 0 && check[i][j] == false)
				{
					int prev = arr[i][j];
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					check[i][j] = true;
					bfs(q, prev);
				}
			}
		}
		
		if (!flag)
		{
			//평균 보다 작은수 +1 큰수 -1;
			double avg = 0;
			double sum = 0;
			int count = 0;
			for (int i = 0; i < N; ++i) //평균구하기
			{
				for (int j = 0; j < M; ++j)
				{
					if (arr[i][j] > 0) count += 1;

					sum += arr[i][j];
				}
			}
			
			if (count != 0)
			{
				avg = sum * 1.0 / count;
				for (int i = 0; i < N; ++i)
				{
					for (int j = 0; j < M; ++j)
					{
						if (arr[i][j] != 0 && arr[i][j] > avg)
						{
							arr[i][j] -= 1;
						}
						else if (arr[i][j] != 0 && arr[i][j] < avg)
						{
							arr[i][j] += 1;
						}
					}
				}
			}

		}
		
		//원판의 합
		int ssum = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				ssum += arr[i][j];
			}
		}
		ans = ssum;
	}

	cout << ans << '\n';
	return 0;
}
void rotate(int x, int dir, int n)
{
	//x , dir, n  : x배수, 방향, 회전 횟수.
	if (dir == 1) // CCW
	{
		int row = 0;
		for (int i = x; i <= N; i=i+x)
		{
			 row = i-1;
			 for (int k = 0; k < n; ++k) //n번 회전
			 {
				 int temp = arr[row][0];
				 vector<int> v(M);
				 for (int w = 0; w < M; ++w)
				 {
					 v[w] = arr[row][w];
				 }
				 for (int j = 0; j < M - 1; ++j) //column
				 {
					 arr[row][j] = v[j+1];
				 }
				 arr[row][M - 1] = temp;
			 }
		}
	}
	else // CW
	{
		int row = 0;
		for (int i = x; i <= N; i=i+x)
		{
			row = i - 1;
			for (int k = 0; k < n; ++k) //n번 회전
			{
				int temp = arr[row][M-1];
				vector<int> v(M);
				for (int w = 0; w < M; ++w)
				{
					v[w]=arr[row][w];
				}
				for (int j = 0; j < M - 1; ++j) //column
				{
					arr[row][j + 1] = v[j];
				}
				arr[row][0] = temp;
			}
		}

	}
}
void bfs(queue<pair<int, int>> &q, int prev)
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

			//
			
			if (yn >= M) yn = yn % M;
			if (yn < 0) yn = M - 1;
			//
			if (xn < 0 || xn >= N || yn < 0 || yn >= M) continue;

			if (check[xn][yn] == false && arr[xn][yn] == prev)
			{
				check[xn][yn] = true;
				arr[x][y] = 0; arr[xn][yn] = 0;
				flag = true;
				q.push(make_pair(xn, yn));
			}
		}
	}
}