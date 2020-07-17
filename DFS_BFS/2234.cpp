#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


int castle[50][50];

int check_room[50][50]; //1.���� ����
int room_count[2550]; //2.���� ���� ���� ����

int broken_check[50][50]; //3. ���� �Ѱ� �μ��� �ִ� ���� ����


int dx[] = { 0,-1,-0,1 };
int dy[] = { -1,0,1,0 };
int N, M;

void bfs(int x, int y, int component);
void broken_bfs(int x, int y, int component, int &des_x, int &des_y, bool &out_diff);
int main(void)
{
	cin >> M >> N;
	//�Է�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> castle[i][j];
	}

	// 1. ���� �ִ� ���� ����

	int component = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (check_room[i][j] == 0)
			{
				component += 1;
				bfs(i, j, component);
			}
		}
	}
	//���� ���� ���
	cout << component << '\n';


	//2. ���� ���� ���� ����
	for (int j = 0; j < N; ++j)
	{
		for (int k = 0; k < M; ++k)
		{
			room_count[check_room[j][k]] += 1;
		}
	}
	int ans_second = 0;
	for (int i = 1; i <= component; ++i)
	{
		if (ans_second < room_count[i])
			ans_second = room_count[i];
	}
	//���� ���� ���� ���� ���.
	cout << ans_second << '\n';
	
	//3.�ϳ��� ���� �����Ͽ� ���� �� �ִ� ���� ���� ���� ũ��
	//�����Ҹ� ������� BFS ��ȸ
	//���δٸ� �����Ҷ��  ���� �ѹ� �� �㹰�� ���� �ִ밪�� ���غ���. 
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int sum = room_count[check_room[i][j]];
			int des_x = 0;
			int des_y = 0;
			bool isDiff = false;
			broken_bfs(i, j, check_room[i][j], des_x, des_y,isDiff);

			if(isDiff)
				sum += room_count[check_room[des_x][des_y]];

			if (ans < sum)
				ans = sum;
		}
	}
	cout << ans << '\n';
	return 0;
}
void broken_bfs(int x, int y, int component, int &des_x, int &des_y,bool &out_diff)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	broken_check[x][y] = component;
	
	bool isDiff = false;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];

			if (xn < 0 || xn >= N || yn < 0 || yn >= M)
				continue;

			if (broken_check[xn][yn]==false && check_room[xn][yn] == component)
			{
				broken_check[xn][yn] = true;
				q.push(make_pair(xn, yn));
			}
			else if(broken_check[xn][yn]==false && check_room[xn][yn] != component)
			{
				if (isDiff == false)
				{
					isDiff = true;
					out_diff = true;
					des_x = xn;
					des_y = yn;
					memset(broken_check, 0, sizeof(broken_check));
					break;
				}
			}
		}
	}
}
void bfs(int x, int y, int component)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check_room[x][y] = component;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int xn = x + dx[i];
			int yn = y + dy[i];
			
			if (xn < 0 || xn >= N || yn < 0 || yn >= M) 
				continue;

			if (castle[x][y] & (1 << i)) 
				continue; //���� ������
			
			if (check_room[xn][yn] == 0)
			{
				check_room[xn][yn] = component;
				q.push(make_pair(xn, yn));
			}
		}
	}
}