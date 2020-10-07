#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<vector<int>> mag(4, vector<int>(8, 0));
vector<pair<int, int>> RotatedInfo;
int dx[] = { -1,1 };
bool check[4];

void Simulate(vector<pair<int, int>> info);
void Go(int idx, int dir);
void RotateMag();
int Calc();

int Calc()
{
	int ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (mag[i][0] == 1)
			ret += (1 << i);
	}
	return ret;
}
void RotateMag()
{
	for (int i = 0; i < RotatedInfo.size(); ++i)
	{
		int idx = RotatedInfo[i].first;
		int dir = RotatedInfo[i].second;

		if (dir > 0) //cw
		{
			int end = mag[idx].back();

			for (int i = 6; i >= 0; --i)
				mag[idx][i + 1] = mag[idx][i];

			mag[idx][0] = end;
		}
		else //ccw
		{
			int head = mag[idx][0];

			for (int i = 1; i < 8; ++i)
				mag[idx][i - 1] = mag[idx][i];

			mag[idx][7] = head;
		}
	}
}
void Go(int idx, int dir)
{
	check[idx] = true;
	RotatedInfo.push_back({ idx,dir });
	int current = idx;

	for (int i = 0; i < 2; ++i) //-1, 1
	{
		int side = current + dx[i];  //current  :3 , side 2  //side 4

		if (side < 0 || side >= 4) continue;

		if (check[side] == false)
		{
			if (side < current) 
			{
				if (mag[current][6] != mag[side][2])
					Go(side, dir*-1);
			}
			else if (side > current)
			{
				if (mag[current][2] != mag[side][6])
					Go(side, dir*-1);
			}
		}
	}
}

void Simulate(vector<pair<int, int>> info)
{
	for (int i = 0; i < info.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
			check[j] = false;
		RotatedInfo.clear();

		Go(info[i].first - 1, info[i].second);
		RotateMag();
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	deque<int> dq(8);


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int k = 0;
		cin >> k;
		vector<pair<int, int>> rotate_info;
		vector<vector<int>> _empty(4, vector<int>(8, 0));
		mag = _empty;

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 8; ++j)
				cin >> mag[i][j];

		deque<int> dq(8);
		vector<int>ab = mag[0];
		
		int mag_num, rotDir;

		for (int i = 0; i < k; ++i)
		{
			cin >> mag_num >> rotDir;
			rotate_info.push_back({ mag_num,rotDir });
		}

		Simulate(rotate_info);
		cout << "#" << test_case << " " << Calc() << '\n';
	}
	return 0;
}