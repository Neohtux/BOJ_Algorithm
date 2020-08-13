#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int ccw_dx[] = { 0,-1,0,1 };
int ccw_dy[] = { 1,0,-1,0 };

int cw_dx[] = { 0,1,0,-1 };
int cw_dy[] = { 1,0,-1,0 };
int R, C, T;
vector<pair<int, int>> cleaner;
void Input();
void Solve();
void Spread_dust();
void go_Cleaner(int x, int y, char ch);
int ans;
int main(void)
{
	Input();
	Solve();
	return 0;
}

void Solve()
{
	for (int i = 0; i < T; ++i)
	{
		Spread_dust();
		go_Cleaner(cleaner[0].first, cleaner[0].second, 't');
		go_Cleaner(cleaner[1].first, cleaner[1].second, 'b');
	}
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] == -1)continue;

			ans += map[i][j];
		}
	}
	cout << ans << '\n';
}
void go_Cleaner(int x, int y, char ch)
{
	int copy_map[50][50];
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			copy_map[i][j] = map[i][j];
	}
	if (ch == 't') //ccw
	{
		int xn = x;
		int yn = y + 1;
		map[xn][yn] = 0;
		for (int i = 0; i < 4; ++i)
		{
			while (true)
			{
				int cur_x = xn;
				int cur_y = yn;
				xn += ccw_dx[i];
				yn += ccw_dy[i];

				if (xn < 0 || xn >= R || yn < 0 || yn >= C)
				{
					xn -= ccw_dx[i];
					yn -= ccw_dy[i];
					break;
				}

				if (xn == x && yn == y) //청소기 있는곳에 도착했을때
					break;

				map[xn][yn] = copy_map[cur_x][cur_y];
			}
		}
	}
	else
	{
		int xn = x;
		int yn = y + 1;
		map[xn][yn] = 0;
		for (int i = 0; i < 4; ++i)
		{
			while (true)
			{
				int cur_x = xn;
				int cur_y = yn;
				xn += cw_dx[i];
				yn += cw_dy[i];

				if (xn < 0 || xn >= R || yn < 0 || yn >= C)
				{
					xn -= cw_dx[i];
					yn -= cw_dy[i];
					break;
				}

				if (xn == x && yn == y) //청소기 있는곳에 도착했을때
					break;

				map[xn][yn] = copy_map[cur_x][cur_y];
			}
		}
	}

}
void Spread_dust()
{
	int copy_map[50][50];
	memset(copy_map, 0, sizeof(copy_map));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] != 0 && map[i][j] != -1) //먼지인 경우
			{
				for (int k = 0; k < 4; ++k)
				{
					int xn = i + dx[k]; //확산 되는 x좌표
					int yn = j + dy[k]; //확산 되는 y좌표

					if (xn >= 0 && xn < R && yn >= 0 && yn < C)
					{
						if (map[xn][yn] != -1) //청소기가 아닌경우
						{
							int sp_dust = map[i][j] / 5;
							copy_map[i][j] -= sp_dust;
							copy_map[xn][yn] += sp_dust;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			map[i][j] += copy_map[i][j];
	}
}
void Input()
{
	cin >> R >> C >> T;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
				cleaner.push_back(make_pair(i, j));
		}
	}
}