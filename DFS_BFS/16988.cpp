#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int bfs(int x, int y);
void go(int cnt, int idx);

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

//1
int check[20][20];
int check_2[20][20];
int map[20][20];
//2

vector<pair<int, int>> white_pos;
vector<pair<int, int>> zero_pos;
int N, M;

int prev_com;
int next_com;
int ans;
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				zero_pos.push_back(make_pair(i, j));
			if (map[i][j] == 1) 
				check[i][j] = true;

			if (map[i][j] == 2)
				white_pos.push_back(make_pair(i, j));
		}
	}

	go(0,0);
	cout << ans << '\n';
	return 0;
}

void go(int cnt,int idx)
{
	if (cnt == 2)
	{
		int tmp_sum = 0;
		memset(check_2, 0, sizeof(check_2));
		for (int i = 0; i < white_pos.size(); ++i)
		{
			int x = white_pos[i].first;
			int y = white_pos[i].second;
			if (map[x][y] == 2 && check_2[x][y] == false)
			{
				int temp = bfs(x, y);
				if (temp == -1)
					continue;

				else tmp_sum += temp;
			}
		}

		if (ans < tmp_sum)
			ans = tmp_sum;

		return;
	}
	for (int i = idx; i < zero_pos.size(); ++i)
	{
		int x = zero_pos[i].first;
		int y = zero_pos[i].second;

		if (map[x][y] == 0 && check[x][y] == false)
		{
			check[x][y] = 1;
			map[x][y] = 1;
			go(cnt + 1, i + 1);
			check[x][y] = 0;
			map[x][y] = 0;
		}
	}
	
}

int bfs(int x, int y)
{
	int result_size = 1;
	bool flag = false;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check_2[x][y] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];
			
			if (xn < 0 || xn >= N || yn < 0 || yn >= M) continue;
			
				
			if (check_2[xn][yn] == false && map[xn][yn] == 2)
			{
				check_2[xn][yn] = true;
				result_size += 1;
				q.push(make_pair(xn, yn));
			}
			else if (check_2[xn][yn] == false && map[xn][yn] == 0)
			{
				flag = true;
			}
		}	
	}
	if (flag)
		return -1;
	return result_size;
}