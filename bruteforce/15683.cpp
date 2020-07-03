#include<iostream>
#include<vector>

char mat[8][8];
char copy_mat[8][8];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
using namespace std;
int N, M;
int CAM_CNT;
int ans = 70;
vector<pair<pair<int, int>, char>> CAM; //x,y, n번 카메라
vector<int> dir_list;
void go(vector<int> &v, int cnt);
void check_video(vector<pair<pair<int, int>, char>> &CAM, vector<int> &dirlist);
void play_video(int x, int y, int dir);
int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> mat[i][j];
			if (mat[i][j] != '0' && mat[i][j] != '6')
			{
				CAM.push_back(make_pair(make_pair(i, j), mat[i][j]));
				CAM_CNT += 1;
			}
		}
	}
	//방향 구하기
	go(dir_list, 0);
	cout << ans << '\n';
	return 0;
}
void go(vector<int> &v, int cnt)
{
	if (cnt == CAM_CNT)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				copy_mat[i][j] = mat[i][j];
		}
		
		check_video(CAM,v);
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (copy_mat[i][j] == '0')
				{
					sum += 1;
				}
			}
		}
		if (ans > sum)
			ans = sum;
		return;
	}
	vector<int> a(v);
	for (int i = 0; i < 4; ++i)
	{
		a.push_back(i);
		go(a, cnt + 1);
		a.pop_back();
	}
}
void check_video(vector<pair<pair<int, int>, char>> &CAM, vector<int> &dirlist)
{
	
	for(int i=0; i<CAM_CNT;++i)
	{
		int x = CAM[i].first.first;
		int y = CAM[i].first.second;
		char cam_num = CAM[i].second;

		int dir = dirlist[i];
		switch (cam_num)
		{
		case '1':
			play_video(x, y, dir);
			break;
		case '2':
			if (dir % 2) //1,3
			{
				play_video(x, y, 1);
				play_video(x, y, 3);
			}
			else //0,2
			{
				play_video(x, y, 0);
				play_video(x ,y, 2);
			}
			break;
		case '3':
			if (dir == 0) // 0,1
			{
				play_video(x, y, 0);
				play_video(x, y, 1);
			}
			else if (dir==1)// 1,2
			{
				play_video(x, y, 1);
				play_video(x, y, 2);
			}
			else if (dir == 2) // 2,3
			{
				play_video(x, y, 2);
				play_video(x, y, 3);
			}
			else if (dir == 3) //3,4
			{
				play_video(x, y, 3);
				play_video(x, y, 0);
			}
			break;
		case '4':
			if (dir == 0) // 3,0,1
			{
				play_video(x, y, 3);
				play_video(x, y, 0);
				play_video(x, y, 1);
			}
			else if (dir == 1)// 0,1,2
			{
				play_video(x, y, 0);
				play_video(x, y, 1);
				play_video(x, y, 2);
			}
			else if (dir == 2) // 1,2,3
			{
				play_video(x, y, 1);
				play_video(x, y, 2);
				play_video(x, y, 3);
			}
			else if (dir == 3) //2,3,0
			{
				play_video(x, y, 2);
				play_video(x, y, 3);
				play_video(x, y, 0);
			}
			break;
		case '5':
			play_video(x, y, 0);
			play_video(x, y, 1);
			play_video(x, y, 2);
			play_video(x, y, 3);
			break;
		}
		int aaa = 0;
	}
}
void play_video(int x, int y, int dir)
{
	//copy_mat[8][8]
	int xn = x;
	int yn = y;
	while (1)
	{
		xn += dx[dir];
		yn += dy[dir];

		if (xn >= 0 && xn < N && yn >= 0 && yn < M)
		{
			if (copy_mat[xn][yn] == '6') break;
			
			if (copy_mat[xn][yn] == '0' || copy_mat[xn][yn] == '#')
					copy_mat[xn][yn] = '#';	
		}
		else break;
	}
}