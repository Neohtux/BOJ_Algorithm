#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int check[50][50];
int arr[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N,M;

vector<pair<int, int>> virus_pos;
vector<int> virus_list;
bool check_virus[10];
void Input();
void choice_virus(int cnt, int idx);
void bfs(vector<int> &v);
bool Check_state();
int tmp_ans;
int ans=987654321;
int main(void)
{
	Input();
	choice_virus(0, 0);

	if (ans == 987654321)
		cout << -1 << '\n';
	else if (ans == 0)
		cout << 0 << '\n';
	else cout << ans-1 << '\n';

	return 0;
}
void bfs(vector<int> &v)
{
	int copy_map[50][50];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			copy_map[i][j] = 0;

			if (arr[i][j] == 1)
				copy_map[i][j] = check[i][j] = 1;
		}
			
	queue<pair<int, int>>q;
	for (int i = 0; i < v.size(); ++i)
	{
		//v에 있는 내용이 (virus 몇번째 몇번째 할건지 M개)
		int x = virus_pos[virus_list[i]].first;
		int y = virus_pos[virus_list[i]].second;
		check[x][y] = 1;
		copy_map[x][y] = 2;
		q.push(make_pair(x, y));
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];

			if (xn < 0 || xn >= N || yn < 0 || yn >= N) continue;

			if (check[xn][yn] == 0 &&copy_map[xn][yn]==0)
			{
				check[xn][yn] = check[x][y] + 1;
				tmp_ans = check[xn][yn];
				q.push(make_pair(xn, yn));
			}
		}
	}


}
bool Check_state()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (check[i][j] == 0)
				return false;

	return true;
}
void choice_virus(int cnt, int idx)
{
	if (cnt == M)
	{
		bfs(virus_list);
		bool IsComplete = Check_state();
		
		if (IsComplete) //답의 해를 찾은경우
			if (ans > tmp_ans) 
				ans = tmp_ans;

		memset(check, 0, sizeof(check));
	}

	for (int i = idx; i < virus_pos.size(); ++i)
	{
		if (check_virus[i] == false)
		{
			check_virus[i] = true;
			virus_list.push_back(i);
			choice_virus(cnt + 1, i + 1);
			check_virus[i] = false;
			virus_list.pop_back();
		}
	}
}
void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			if(arr[i][j]==1)
			check[i][j] = arr[i][j];
			if (arr[i][j] == 2)
				virus_pos.push_back(make_pair(i, j));
		}
	}
		
}