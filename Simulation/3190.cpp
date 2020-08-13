#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void Input();
void Solve();
int map[101][101];
int check[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

vector<pair<int, char>> _MoveInfo; // 시간, 방향
deque<pair<int, int>> dq;
int N, K, DIR;
int main(void) { Input(); Solve(); return 0; }
int cur_time;
int ans;
void Simulation(int x, int y, int dir);
bool moving_snake(int& xn, int& yn, int d, int _time, int _curtime);
bool moving_snake(int &xn, int &yn, int d, int _time, int _curtime)
{
	for (int j = cur_time; j < _time; ++j)
	{
		xn = xn + dx[d];
		yn = yn + dy[d];

		if (xn <= 0 || xn > N || yn <= 0 || yn > N) //벽에 부딪힌 경우
		{
			ans += 1;
			return false;
		}

		if (check[xn][yn] == 1) //자신의 몸이랑 부딪힌 경우
		{
			ans += 1;
			return false;
		}

		//사과가 없는 경우
		if (map[xn][yn] == 0)
		{
			int cur_x = dq.back().first;
			int cur_y = dq.back().second;
			check[cur_x][cur_y] = false;
			dq.pop_back();

			check[xn][yn] = true;
			dq.push_front(make_pair(xn, yn));

			ans += 1;
		}
		else if (map[xn][yn] == 2) //사과가 있는 경우
		{
			map[xn][yn] = 0;
			check[xn][yn] = true;
			dq.push_front(make_pair(xn, yn));

			ans += 1;
		}
	}
	return true;
}
void Simulation(int x, int y, int dir)
{
	int xn = x;
	int yn = y;
	int d = dir;
	bool is_go = true;
	for (int i = 0; i < _MoveInfo.size(); ++i)
	{
		int _time = _MoveInfo[i].first;
		char _dir = _MoveInfo[i].second;
		cur_time = ans;
		bool isgo = moving_snake(xn, yn, d, _time, cur_time);
		if (isgo)
		{
			if (_dir == 'D')
			{
				d = (d + 1) % 4;
			}
			else if (_dir == 'L')
			{
				d = d - 1;
				if (d < 0) d = 3;
			}
		}
		else
		{
			is_go = false;
			break;
		}
	}
	if (is_go == false)
	{
		cout << ans << '\n';
		return;
	}
	else
	{
		int n_x = xn;
		int n_y = yn;
		while (true)
		{
			n_x += dx[d];
			n_y += dy[d];

			if (check[n_x][n_y] == 1)
			{
				ans += 1;
				break;
			}
			if (n_x <= 0 || n_x > N || n_y <= 0 || n_y > N)
			{
				ans += 1;
				break;
			}
			ans += 1;
		}
		cout << ans << '\n';
		return;
	}

}
void Solve()
{
	dq.push_back(make_pair(1, 1));
	Simulation(1, 1, 1);

}
void Input()
{
	cin >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		map[a][b] = 2;
	}

	cin >> DIR;

	for (int i = 0; i < DIR; ++i)
	{
		int a = 0;
		char b;
		cin >> a >> b;
		_MoveInfo.push_back(make_pair(a, b));
	}
}