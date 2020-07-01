#include<iostream>
#include<vector>

using namespace std;
void go(long long n, vector<long long> &ans_v);

int N;
vector<long long> v(N);
bool isend = false;
int main(void)
{
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		long long a=0;
		cin >> a;
		v.push_back(a);
	}
		
	for (int i = 0; i < N; ++i)
	{
		vector<long long> ans_v;
		ans_v.push_back(v[i]); //N-1�� ����
		go(v[i], ans_v);
	}
	return 0;
}
void go(long long n, vector<long long> &ans_v)
{
	if (isend) return;
	if (ans_v.size() == N) //������3 ���ϱ�2�� N-1�� �Ϸ��� ��� ���
	{
		for (int i = 0; i < ans_v.size(); ++i)
		{
			cout << ans_v[i] << ' ';
		}
		cout << '\n';
		isend = true; //�ѹ��� ����ϰ� ����.
		return;
	}
	
	long long tmp=0;
	bool isgo = false;
	if (n% 3 == 0) //3���� ������ �������� ���
	{
		isgo = true;
		tmp = n / 3;
	}
	long long tmp_2 = n * 2;

	for (int i = 0; i < N; ++i)
	{
		if (tmp == v[i] && isgo) //������3  case1
		{
			ans_v.push_back(tmp);
			go(tmp, ans_v);
		}

		if (tmp_2 == v[i]) //���ϱ�2 case2
		{
			ans_v.push_back(tmp_2);
			go(tmp_2, ans_v);
		}
	}
}