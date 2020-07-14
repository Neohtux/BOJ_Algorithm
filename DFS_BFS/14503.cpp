#include<iostream>
#include<queue>
using namespace std;

int arr[50][50];
int check[50][50];
int N, M;
queue<pair<pair<int, int>,int>> q;
void bfs();
void dfs(int x, int y, int dir);
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 0;
int main(void)
{
	cin >> N >> M;
	
	int pos_x, pos_y, dir;
	cin >> pos_x >> pos_y >> dir;
	q.push(make_pair(make_pair(pos_x, pos_y), dir));
	ans += 1;
	check[pos_x][pos_y] = true;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	}
	//bfs();
	dfs(pos_x, pos_y, dir);



	cout << ans << '\n';
	return 0;
}
void dfs(int x, int y, int dir)
{
	int cur_x = x;
	int cur_y = y;
	//int cur_dir = dir;
	check[cur_x][cur_y] = true;
	int next_dir = dir;
	bool isBack = false;
	for (int i = 0; i < 4; ++i) //a,b
	{
		next_dir = next_dir - 1;
		if (next_dir < 0) next_dir = 3;

		int xn = cur_x + dx[next_dir];
		int yn = cur_y + dy[next_dir];

		if (xn < 0 || xn >= N || yn < 0 || yn >= M) continue;

		if (arr[xn][yn] == 0 && check[xn][yn] == 0) 
		{
			 //a
			ans += 1;
			isBack = true;
			dfs(xn, yn, next_dir);
			break;
		}
	}

	if (isBack == false)
	{
		int new_dir = next_dir + 2;
		new_dir = new_dir % 4;

		int new_xn = cur_x + dx[new_dir];
		int new_yn = cur_y + dy[new_dir];

		if (new_xn >= 0 || new_xn < N || new_yn >= 0 || new_yn < M)
		{
			if (arr[new_xn][new_yn] != 1)
			{
				dfs(new_xn, new_yn, next_dir);
			}
		}

	}

}
void bfs()
{
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cur_dir = q.front().second;
		
		int next_dir = cur_dir;
		int xn = 0;
		int yn = 0;
		q.pop();
		bool isBack = false;
		for (int i = 0; i < 4; ++i)
		{
			next_dir = next_dir - 1;
			if (next_dir < 0) next_dir = 3; //a. 방향 회전.

			xn = cur_x + dx[next_dir];
			yn = cur_y + dy[next_dir]; // a. 다음칸 지정 
			
			if (xn < 0 || xn >= N || yn < 0 || yn >= M) continue;

			if (arr[xn][yn] == 0 && check[xn][yn] == false)
			{
					check[xn][yn] = true;
					q.push(make_pair(make_pair(xn, yn), next_dir)); //다음칸 전진
					isBack = true;
					break; //1번부터 진행
			}
		}
		if (isBack == false)
		{
			// c번 
				//뒤로 한칸 후진.
				int new_move = next_dir + 2;
				new_move = new_move % 4;
				xn = cur_x + dx[new_move];
				yn = cur_y + dy[new_move];
				if (xn < 0 || xn >= N || yn < 0 || yn >= M) continue;
				
				if (arr[xn][yn] != 1)
				{
					q.push(make_pair(make_pair(xn, yn), next_dir));
				}
		
		}
	}
}