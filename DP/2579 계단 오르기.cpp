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

	//연속 3이상 계단을 밟을 수 없다. 
	
	// 다음 계단을 밟는경우 1 -> 2 , 다다음 계단을 밟는 경우 1 -> 1
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
	//마지막 도착 계단은 반드시 밟는다.
	// -> 거꾸로 생각하면 어떨까 마지막 계단에서 -> 맨 아랫층 까지 내려간다.

	cout << go(N - 1, 1) << '\n';
	return 0;
}