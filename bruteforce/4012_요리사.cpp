/*#include<iostream>
#include<vector>
using namespace std;

int grocery[16][16];
bool check[16];

int divCnt = 0;
int N = 0;
int ans;
void DivideCook(int idx,int cnt)
{
	if (cnt == divCnt)
	{
		vector<int> A, B;
		for (int i = 0; i < N; ++i)
		{
			if (check[i]) A.push_back(i);
			else B.push_back(i);
		}

		int A_flavor = 0, B_flavor = 0;
		for (int i = 0; i < divCnt; ++i)
		{
			for (int j = 0; j < divCnt; ++j)
			{
				if (i == j) continue;
				A_flavor += grocery[A[i]][A[j]];
				B_flavor += grocery[B[i]][B[j]];

			}
		}
		int _diff = A_flavor - B_flavor;
		if (_diff < 0) _diff = -_diff;

		if (ans > _diff)
			ans = _diff;
		return;
	}

	for (int i = idx; i < N; ++i)
	{
		if (check[i] == false)
		{
			check[i] = true;
			DivideCook(i + 1, cnt + 1);
			check[i] = false;
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 1e9;
		cin >> N;
		divCnt = N / 2;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> grocery[i][j];
		
		DivideCook(0,0);

		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}*/