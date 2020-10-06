#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int stairs[305];
int cache[305][3];

int go(int idx, int depth)
{
	if (idx < 0)
		return 0;

	int &ret = cache[idx][depth];

	if (ret != -1)
		return ret;

	//���� 3�̻� ����� ���� �� ����. 
	
	// ���� ����� ��°�� 1 -> 2 , �ٴ��� ����� ��� ��� 1 -> 1
	if (depth < 2)
		ret = max(go(idx - 1, 2),go(idx-2,1)) + stairs[idx];

	//
	else
		ret = max(ret , go(idx - 2, 1)+stairs[idx]);

	return ret;

}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> stairs[i];

	memset(cache, -1, sizeof(cache));
	//������ ���� ����� �ݵ�� ��´�.
	// -> �Ųٷ� �����ϸ� ��� ������ ��ܿ��� -> �� �Ʒ��� ���� ��������.

	cout << go(N - 1, 1) << '\n';
	return 0;
}