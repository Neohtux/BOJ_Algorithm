#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int H,W,N;
vector<pair<int, int>> v;

bool check[100];
void go(int index, int cnt);
int ans = 0;

int main(void)
{
	cin >> H >> W;
	cin >> N;

	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	go(0, 0);
	cout << ans << '\n';
	return 0;
}
void go(int index, int cnt)
{
	if (cnt == 2)
	{
		int x1, y1, x2, y2;
		bool isSecond = false;
		for (int i = 0; i < N; ++i)
		{
			if (check[i])
			{
				if (isSecond == false)
				{
					x1 = v[i].first;
					y1 = v[i].second;
					isSecond = true;
				}
				else 
				{
					x2 = v[i].first;
					y2 = v[i].second;
				}
					
			}		
		}
		//��ƼĿ ���̱�
		//���̴°��� �������� (���� ,����) swap
		//���� ��ƼĿ�� ������
		//���� ���� �ִ밪����

		//��ƼĿ ���̱� ��� ���� ���ΰ�.
		// 2���� ��ƼĿ ���μ��� =2^2 (4����)
		//�Ѥ� �Ѥ� �Ӥ� �Ӥ� 4����
		//���η� �����ؼ� ���̳�, ���η� �����ؼ� ���̳� (2����)
		for (int q = 0; q < 2; ++q)
		{
			for (int w = 0; w < 2; ++w)
			{
				//���η� ���϶�
				if (x1+x2 <= H && max(y1, y2) <= W)
				{
					int sum = (x1 * y1) + (x2 * y2);
					if (ans < sum)
						ans = sum;
				}
				// ���η� ���϶�
				else if (max(x1,x2) <= H && y1 + y2 <= W)
				{
					int sum = (x1 * y1) + (x2 * y2); 
					if (ans < sum)
						ans = sum;
				}
				swap(x2, y2);
			}
			swap(x1, y1);
		}
		return;
	}

	for (int i = index; i < N; ++i)
	{
		if (check[i]==false)
		{
			check[i] = true;
			go(i+1, cnt + 1);
			check[i] = false;
		}
		
	}
}
