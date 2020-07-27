//������ �ΰ��� ������
// �� ������ �μ��� �� �ϳ��� ���ԵǾ�� �Ѵ�.
// ���ű��� ���ԵǾ� �ִ� ������ ��� ����Ǿ� �־�� ��.
   //������ ���� ����, 
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void Input();
void divide_zone(int cnt, int idx, int limit);
bool check_choice[11];

int check_zone[11];
bool visited[11];
int popu[11];
int N;
vector<int> v[11];
int ans = 987654321;
int Check_func();
bool _t_zone;
bool _f_zone;
void dfs(int node, bool flag);
int GetPopulation(vector<int> &t_zone, vector<int> &f_zone);
int main(void)
{
	Input();
	for (int i = 1; i <= N; ++i)
	{
		divide_zone(0, 1, i);
	}
		
	if (ans == 987654321)
		cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
void dfs(int node,bool flag)
{
	visited[node] = true;
	
	for (int i = 0; i < v[node].size(); ++i)
	{
		int next = v[node][i];

		if (visited[next] == false && check_choice[next] == flag)
		{
			dfs(next, flag);
		}
	}
}
//�� ������ �α����� ���ϱ�
int GetPopulation(vector<int> &t_zone, vector<int> &f_zone)
{
	int t_sum = 0, f_sum = 0;
	int result_sub = 0;

	for (int i = 0; i < t_zone.size(); ++i)
		t_sum += popu[t_zone[i]];
	for (int i = 0; i < f_zone.size(); ++i)
		f_sum += popu[f_zone[i]];

	result_sub = t_sum - f_sum;

	if (result_sub < 0) result_sub = -result_sub;

	return result_sub;
}
int Check_func()
{
	vector<int> t_zone, f_zone;
	_t_zone = true;
	_f_zone = true;
	for (int i = 1; i <= N; ++i)
	{
		if (check_choice[i]) t_zone.push_back(i);
		else f_zone.push_back(i);
	}
	// �� ������ �μ��� �� �ϳ��� ���ԵǾ�� �Ѵ�.
	if (t_zone.size() == 0 || f_zone.size() == 0) return false;

	//T ���� Ȯ��
	// ���ű��� ���ԵǾ� �ִ� �������� �˻�.
	dfs(t_zone[0],true);
	// �����Ұ� ����Ʈ�� ��ġ�ϴ��� Ȯ��
	for (int i = 0; i < t_zone.size(); ++i)
	{
		if (visited[t_zone[i]] == false) 
			_t_zone = false;
	}
	memset(visited, 0, sizeof(visited));
	
	//F ���� Ȯ��
	dfs(f_zone[0],false); //false �ε����� true
	for (int i = 0; i < f_zone.size(); ++i)
	{
		if (visited[f_zone[i]] == false) 
			_f_zone = false;
	}
	memset(visited, 0, sizeof(visited));
	// ���ű��� ���ԵǾ� �ִ� ������ ��� ����Ǿ� �־�� ��.
	if (_t_zone == true && _f_zone == true)
	{
		return GetPopulation(t_zone, f_zone);
	}
	else return -1;
}

void divide_zone(int cnt, int idx, int limit)
{
	if (cnt == limit)
	{
		int tmp_sub = Check_func();
		
		//���� �ظ� ã�����
		if (tmp_sub != -1)
		{
			if (ans > tmp_sub)
				ans = tmp_sub;
		}
		return;
	}

	for (int i = idx; i < N; ++i)
	{
		if (check_choice[i] == false)
		{
			check_choice[i] = true;
			divide_zone(cnt + 1, i + 1,limit);
			check_choice[i] = false;
		}
	}

}
void Input()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> popu[i];

	for (int i = 1; i <= N; ++i)
	{
		int n_cnt;
		cin >> n_cnt;
		for (int j = 0; j < n_cnt; ++j)
		{
			int node;
			cin >> node;
			v[i].push_back(node);
		}
	}

}