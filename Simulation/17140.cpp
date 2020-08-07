#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b);
void Input();
void Solve();
vector<pair<int, int>> Get_calculateRC(int idx, int size, char row_col);

int map[101][101];
int num_count[101];
bool num_check[101];
int R, C, K;
int main(void)
{

	Input();
	Solve();
	
	return 0;
}
vector<pair<int, int>> Get_calculateRC(int idx,int size, char row_col)
{
	memset(num_count, 0, sizeof(num_count));
	memset(num_check, 0, sizeof(num_check));
	vector<pair<int, int>> result_vector;
	if (row_col == 'R') //행에서 원소, 횟수 검사
	{
		//해당 원소가 등장하는 횟수 검사.
		for (int i = 1; i <=size; ++i) 
		{
			num_count[map[idx][i]] += 1;
		}
		//원소, 횟수 추가
		for (int i = 1; i <= size; ++i)
		{
			int num = map[idx][i];
			if (num == 0) continue;

			int num_cnt = num_count[num];
			if (num_check[num] == false)
			{
				num_check[num] = true;
				result_vector.push_back(make_pair(num, num_cnt));
			}
		}

	}
	else //열에서 원소, 횟수 검사.
	{
		//해당 원소가 등장하는 횟수 검사.
		for (int i = 1; i <=size; ++i)
		{
			num_count[map[i][idx]] += 1;
		}
		//원소, 횟수 추가
		for (int i = 1; i <= size; ++i)
		{
			int num = map[i][idx];
			if (num == 0) continue;

			int num_cnt = num_count[num];
			if (num_check[num] == false)
			{
				num_check[num] = true;
				result_vector.push_back(make_pair(num, num_cnt));
			}
		}
	}
	
	return result_vector;
}
void Solve()
{
	int row_size = 3;
	int col_size = 3;
	int ans = 0;
	while (1)
	{
		if (map[R][C] == K)
		{
			cout << ans << '\n';
			return;
		}
		if (ans > 100)
		{
			cout << -1 << '\n';
			return;
		}
		//R연산
		if (row_size >= col_size)
		{
			//행 정렬
			//행에서 (원소 수, 횟수)가 몇번 나왔는지
			//(원소 수,횟수) 정렬
			// map에 저장

			int max_size = 0;
			for (int row_index = 1; row_index <= row_size; ++row_index)
			{
				//1.행에서 (원소 수, 횟수)가 몇번 나왔는지
				vector<pair<int, int>> v = Get_calculateRC(row_index, col_size, 'R');


				//2.(원소 수, 횟수) 정렬
				sort(v.begin(), v.end(), compare);

				//3 map에 저장 
				//(1) 0을 먼저 채운다

				for (int i = 1; i <= col_size; ++i)
					map[row_index][i] = 0;

				//(2) v를 map에 wirte 한다.

				int write_pos = 1; //write pos
				for (int j = 0; j < v.size(); ++j)
				{
					map[row_index][write_pos++] = v[j].first;
					map[row_index][write_pos++] = v[j].second;
				}

				//열이 최대 몇개인지 
				if (max_size < 2 * v.size())
					max_size = 2 * v.size();

			}
			col_size = max_size;
		}
		//C연산
		else
		{
			//열 정렬
			//열에서 (원소 수, 횟수)가 몇번 나왔는지
			//(원소 수,횟수) 정렬
			// map에 저장

			int max_size = 0;
			for (int col_index = 1; col_index <= col_size; ++col_index)
			{
				//1.행에서 (원소 수, 횟수)가 몇번 나왔는지
				vector<pair<int, int>> v = Get_calculateRC(col_index, row_size, 'C');


				//2.(원소 수, 횟수) 정렬
				sort(v.begin(), v.end(), compare);

				//3 map에 저장 
				//(1) 0을 먼저 채운다

				for (int i = 1; i <= col_size; ++i)
					map[i][col_index] = 0;

				//(2) v를 map에 wirte 한다.

				int write_pos = 1; //write pos
				for (int j = 0; j < v.size(); ++j)
				{
					map[write_pos++][col_index] = v[j].first;
					map[write_pos++][col_index] = v[j].second;
				}

				//행이 최대 몇개인지 
				if (max_size < 2 * v.size())
					max_size = 2 * v.size();

			}
			row_size = max_size;
		}
		ans += 1;
	}
}
void Input()
{
	cin >> R >> C >> K;
	
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
			cin >> map[i][j];
	}
}

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second) // second 갯수가 같다면
		return a.first < b.first; //first 수의 오름차순
	
	else return a.second < b.second;
}