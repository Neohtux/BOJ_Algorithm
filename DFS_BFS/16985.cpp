#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dy[] = { 0,-1,0,0,1,0 };
int dx[] = { 0,0,1,0,0,-1 };
int dz[] = { 1,0,0,-1,0,0 };

int maze[5][5][5];
int divided_maze[5][5][5];
int copy_maze[5][5][5];
int check[5][5][5];

bool maze_check[5];
vector<int> maze_list;
vector<int> floor_list;
int check_floor[5];
void init_IO();
void go(int cnt);
void Maze_Rotate(int rotate_cnt, int maze_num);
void bfs(int x, int y, int z);
void divide_floor(int cnt);
int ans = 987654321;
int main(void)
{
	init_IO();
	//층 나누기 { 각도 나누기}
	divide_floor(0);
	//go(0);
	if (ans == 987654321)
	{
		cout << -1 << '\n';
	}
	else cout << ans << '\n';
	
	return 0;
}
void divide_floor(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < floor_list.size(); ++i)
		{
			int room_num = floor_list[i];

			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
					divided_maze[i][j][k] = maze[room_num][j][k];
			}
		}
		go(0);
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (check_floor[i] == false)
		{
			check_floor[i] = true;
			floor_list.push_back(i);
			divide_floor(cnt + 1);
			check_floor[i] = false;
			floor_list.pop_back();
		}
	}
}
void Init_Maze_and_check()
{
	for (int z = 0; z < 5; ++z)
	{
		for (int x = 0; x < 5; ++x)
		{
			for (int y = 0; y < 5; ++y)
				copy_maze[z][x][y] = divided_maze[z][x][y];
		}
	}
	memset(check, 0, sizeof(check));
}
void Maze_Rotate(int rotate_cnt, int maze_num)
{
	int temp[5][5][5];
	for (int cnt = 0; cnt < rotate_cnt; ++cnt)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				temp[maze_num][i][j] = copy_maze[maze_num][j][5 - 1 - i];
			}
		}
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				copy_maze[maze_num][i][j] = temp[maze_num][i][j];
			}
		}
	}
	
}
void bfs(int x, int y, int z)
{
	queue<pair <int, pair<int, int> >> q;
	q.push(make_pair(z, make_pair(x, y)));
	check[z][x][y] = true;

	while (!q.empty())
	{
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		if (x == 4 && y == 4 && z == 4) return;
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			//int zn = z + dz[i];
			int zn = z + dz[i];
			int xn = x + dx[i];
			int yn = y + dy[i];
			
			if (xn < 0 || xn >= 5 || yn < 0 || yn >= 5 || zn < 0 || zn >= 5) continue;

			
			if (check[zn][xn][yn] == false && copy_maze[zn][xn][yn] == 1)
			{
				check[zn][xn][yn] = check[z][x][y]+1;
				q.push(make_pair(zn, make_pair(xn, yn)));
			}
		}
	}
}
void go(int cnt)
{
	//각 회전
	if (cnt == 5)
	{
		//copy_maze = divided_maze
		Init_Maze_and_check();
		//rotate && bfs

		//rotate
		for (int maze_num = 0; maze_num < maze_list.size(); ++maze_num)
		{
			int rotate_cnt = maze_list[maze_num];
			Maze_Rotate(rotate_cnt, maze_num);
		}
		//bfs
		if(copy_maze[0][0][0]==1)
			bfs(0, 0, 0);
		
		check[4][4][4] -= 1;
		if (check[4][4][4] > 0)
		{
			if (ans > check[4][4][4])
				ans = check[4][4][4];
		}
		
		//
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		maze_list.push_back(i);
		go(cnt + 1);
		maze_list.pop_back();
	}
}

void init_IO()
{
	for (int z = 0; z < 5; ++z)
	{
		for (int x = 0; x < 5; ++x)
		{
			for (int y = 0; y < 5; ++y)
			{
				cin >> maze[z][x][y];
				copy_maze[z][x][y] = maze[z][x][y];
			}
				
		}
	}
}