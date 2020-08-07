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
	if (row_col == 'R') //�࿡�� ����, Ƚ�� �˻�
	{
		//�ش� ���Ұ� �����ϴ� Ƚ�� �˻�.
		for (int i = 1; i <=size; ++i) 
		{
			num_count[map[idx][i]] += 1;
		}
		//����, Ƚ�� �߰�
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
	else //������ ����, Ƚ�� �˻�.
	{
		//�ش� ���Ұ� �����ϴ� Ƚ�� �˻�.
		for (int i = 1; i <=size; ++i)
		{
			num_count[map[i][idx]] += 1;
		}
		//����, Ƚ�� �߰�
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
		//R����
		if (row_size >= col_size)
		{
			//�� ����
			//�࿡�� (���� ��, Ƚ��)�� ��� ���Դ���
			//(���� ��,Ƚ��) ����
			// map�� ����

			int max_size = 0;
			for (int row_index = 1; row_index <= row_size; ++row_index)
			{
				//1.�࿡�� (���� ��, Ƚ��)�� ��� ���Դ���
				vector<pair<int, int>> v = Get_calculateRC(row_index, col_size, 'R');


				//2.(���� ��, Ƚ��) ����
				sort(v.begin(), v.end(), compare);

				//3 map�� ���� 
				//(1) 0�� ���� ä���

				for (int i = 1; i <= col_size; ++i)
					map[row_index][i] = 0;

				//(2) v�� map�� wirte �Ѵ�.

				int write_pos = 1; //write pos
				for (int j = 0; j < v.size(); ++j)
				{
					map[row_index][write_pos++] = v[j].first;
					map[row_index][write_pos++] = v[j].second;
				}

				//���� �ִ� ����� 
				if (max_size < 2 * v.size())
					max_size = 2 * v.size();

			}
			col_size = max_size;
		}
		//C����
		else
		{
			//�� ����
			//������ (���� ��, Ƚ��)�� ��� ���Դ���
			//(���� ��,Ƚ��) ����
			// map�� ����

			int max_size = 0;
			for (int col_index = 1; col_index <= col_size; ++col_index)
			{
				//1.�࿡�� (���� ��, Ƚ��)�� ��� ���Դ���
				vector<pair<int, int>> v = Get_calculateRC(col_index, row_size, 'C');


				//2.(���� ��, Ƚ��) ����
				sort(v.begin(), v.end(), compare);

				//3 map�� ���� 
				//(1) 0�� ���� ä���

				for (int i = 1; i <= col_size; ++i)
					map[i][col_index] = 0;

				//(2) v�� map�� wirte �Ѵ�.

				int write_pos = 1; //write pos
				for (int j = 0; j < v.size(); ++j)
				{
					map[write_pos++][col_index] = v[j].first;
					map[write_pos++][col_index] = v[j].second;
				}

				//���� �ִ� ����� 
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
	if (a.second == b.second) // second ������ ���ٸ�
		return a.first < b.first; //first ���� ��������
	
	else return a.second < b.second;
}