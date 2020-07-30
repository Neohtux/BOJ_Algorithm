#include<iostream>
#include<vector>
using namespace std;

int wheel[5][9];
void Input();
void Check_Rotate(int num, int dir);
void Rotate_Wheel(vector<int> &check_list, int dir);
int N;

int main(void)
{
	Input();
	scanf("%d", &N);

	while (N--)
	{
		int wheel_num, dir;
		scanf("%d %d", &wheel_num, &dir);
		Check_Rotate(wheel_num, dir);
	}
	int ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (wheel[i+1][1])
		{
			ans += (1 << i);
		}
	}
	cout << ans << '\n';
	return 0;
}
void Rotate_Wheel(vector<int> &check_list, int dir)
{
	int dir_list[5];
	if (check_list[0] == 2 || check_list[0] == 4)
	{
		dir_list[1] = -dir;
		dir_list[2] = dir;
		dir_list[3] = -dir;
		dir_list[4] = dir;
	}
	else // 1,3
	{
		dir_list[1] = dir;
		dir_list[2] = -dir;
		dir_list[3] = dir;
		dir_list[4] = -dir;
	}
	for (int i = 0; i < check_list.size(); ++i)
	{
		//CW
		
		if (dir_list[check_list[i]] == 1)
		{
			int tmp_arr[9];
			int temp = wheel[check_list[i]][8];
			for (int j = 1; j < 8; ++j)
			{
				tmp_arr[j + 1] = wheel[check_list[i]][j];
			}
			tmp_arr[1] = temp;

			for (int j = 1; j <= 8; ++j)
			{
				wheel[check_list[i]][j] = tmp_arr[j];
			}
		}
		else //CCW
		{
			int tmp_arr[9];
			int temp = wheel[check_list[i]][1];
			for (int j = 1; j < 8; ++j)
			{
				tmp_arr[j] = wheel[check_list[i]][j + 1];
			}
			tmp_arr[8] = temp;

			for (int j = 1; j <= 8; ++j)
			{
				wheel[check_list[i]][j] = tmp_arr[j];
			}
		}
	}
}
void Check_Rotate(int num, int dir)
{
	// [1,3 ] , [2,4]
	vector<int> check_list;
	
	if (num == 1)
	{
		check_list.push_back(num);
		if (wheel[num][3] != wheel[2][7])
		{
			check_list.push_back(2);
			if (wheel[2][3] != wheel[3][7])
			{
				check_list.push_back(3);
				if (wheel[3][3] != wheel[4][7])
				{
					check_list.push_back(4);
				}			
			}
		}
		
	}
	else if (num == 2)
	{
		check_list.push_back(num);

		if (wheel[2][7] != wheel[1][3])
		{
			check_list.push_back(1);
			
		}
		if (wheel[2][3] != wheel[3][7])
		{
			check_list.push_back(3);
			if (wheel[3][3] != wheel[4][7])
				check_list.push_back(4);
		}
		
	}
	else if (num == 3)
	{
		check_list.push_back(num);
		if (wheel[num][3] != wheel[4][7])
		{
			check_list.push_back(4);
		}
		if (wheel[num][7] != wheel[2][3])
		{
			check_list.push_back(2);
			if (wheel[2][7] != wheel[1][3])
				check_list.push_back(1);
		}
		
	}
	else if (num == 4)
	{
		check_list.push_back(num);
		if (wheel[num][7] != wheel[3][3])
		{
			check_list.push_back(3);
			if (wheel[3][7] != wheel[2][3])
			{
				check_list.push_back(2);
				if (wheel[2][7] != wheel[1][3])
					check_list.push_back(1);
			}
		}
	}
	Rotate_Wheel(check_list, dir);
}
void Input()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			scanf("%1d", &wheel[i][j]);
		}
	}
}