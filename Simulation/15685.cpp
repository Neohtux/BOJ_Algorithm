#include<iostream>
#include<vector>
#include<stack>

using namespace std;
void Input();
void Solve();
vector<int> Get_DrangonDir(int dir, int generation);
void move_Dragon(int x, int y, vector<int> &v);
void OutputResult();
int N;
int map[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int ans;
struct D 
{
	int x;
	int y;
	int start_dir;
	int generation;
};
vector<D> dragon_info;

int main(void)
{
	Input();
	Solve();
	return 0;
}

vector<int> Get_DrangonDir(int dir, int generation)
{
	vector<int> dir_sequence;
	dir_sequence.push_back(dir);

	for (int j = 0; j < generation; ++j)
	{
		stack<int> s;
		for (int k = 0; k < dir_sequence.size(); ++k)
		{
			s.push(dir_sequence[k]);
		}


		while (!s.empty())
		{
			int next_dir = s.top();
			s.pop();
			next_dir = (next_dir + 1) % 4;
			dir_sequence.push_back(next_dir);
		}
	}

	return dir_sequence;
}
void move_Dragon(int x, int y, vector<int> &v)
{
	map[y][x] = true;
	int xn = x;
	int yn = y;
	for (int i = 0; i < v.size(); ++i)
	{
		int dir = v[i];
		xn += dx[dir];
		yn += dy[dir];
		map[yn][xn] = true;
	}
}
void Solve()
{
	for (int i = 0; i < dragon_info.size(); ++i)
	{
		int x = dragon_info[i].x;
		int y = dragon_info[i].y;
		int dir = dragon_info[i].start_dir;
		int g = dragon_info[i].generation;

		
		//세대 만큼 반복
		vector<int> dir_list = Get_DrangonDir(dir, g);

		move_Dragon(x, y, dir_list);
	}
	
	OutputResult();
}
void OutputResult()
{
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ans += 1;
		}
	}
	cout << ans << '\n';
}
void Input()
{
	cin >> N;

	int x, y, dir, g;
	D node;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y >> dir >> g;
		node.x = x; 
		node.y = y; 
		node.start_dir = dir; 
		node.generation = g;
		
		dragon_info.push_back(node);
	}
}