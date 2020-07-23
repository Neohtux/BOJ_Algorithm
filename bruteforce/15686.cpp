#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool check_chicken[13];
int _distance[100][13];

int map[50][50];
int check_map[50][50];

void get_Chicken_Distance(int house_x, int house_y, int chicken_x, int chicken_y, int from, int to);
void go(int cnt, int idx, int size, int &sum);
int N, M; 
vector<pair<int, int>> house_pos;
vector<pair<int, int>> chicken_pos;
int main(void)
{
	cin >> N >> M;
	//I/O
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house_pos.push_back(make_pair(i, j));
			if (map[i][j] == 2)
				chicken_pos.push_back(make_pair(i, j));

		}
	}
	for (int i = 0; i < house_pos.size(); ++i)
	{
		for (int j = 0; j < chicken_pos.size(); ++j)
		{
			get_Chicken_Distance(house_pos[i].first, house_pos[i].second,
				chicken_pos[j].first, chicken_pos[j].second,i,j);

			//check_map ÃÊ±âÈ­
			for (int x = 0; x < 50; ++x)
			{
				for (int y = 0; y < 50; ++y)
					check_map[x][y] = false;
			}
		}
	}
	int ans = 987654321;
	int _sum = 987654321;
	
	go(0,0, M, _sum);
	ans = min(ans, _sum);

	cout << ans << '\n';
	return 0;
}
void go(int cnt,int idx, int size,int &sum)
{
	if (cnt == size)
	{
		//
		int _sum = 0;
		for (int house = 0; house < house_pos.size(); ++house)
		{
			int tmp_min = 987654321;
			for (int i = 0; i < chicken_pos.size(); ++i)
			{
				if (check_chicken[i])
				{
					tmp_min = min(tmp_min, _distance[house][i]);
				}
			}
			_sum += tmp_min;
		}
		sum = min(sum,_sum);
		return;
	}

	for (int i = idx; i < chicken_pos.size(); ++i)
	{
		if (check_chicken[i] == false)
		{
			check_chicken[i] = true;
			go(cnt + 1,i+1, size, sum);
			check_chicken[i] = false;
			
		}
	}
}
void get_Chicken_Distance(int house_x, int house_y, int chicken_x, int chicken_y,int from, int to)
{
	queue<pair<int, int>> q;
	q.push(make_pair(house_x, house_y));
	check_map[house_x][house_y] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == chicken_x && y == chicken_y)
		{
			_distance[from][to] = check_map[x][y]-1;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];

			if (xn < 0 || xn >= 50 || yn < 0 || yn >= 50) continue;

			if (check_map[xn][yn] == 0)
			{
				check_map[xn][yn] = check_map[x][y]+1;
				q.push(make_pair(xn, yn));
			}

		}
	}
	
}