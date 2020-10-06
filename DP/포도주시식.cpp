#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int cache[10000][3];
int glass[10000];
int glassCnt = 0;
int go(int idx, int depth)
{
	if (idx >= glassCnt) 
		return 0;

	int &ret = cache[idx][depth];

	if (ret != -1)
		return ret;

	ret = -1e9;
	
	//현재 잔을 마신경우
	if (depth < 2) //연속으로 3잔이상 불가 
		ret = max(ret, go(idx + 1, depth + 1) + glass[idx]);
	
	//마시지 않은경우 , 못하는 경우
	ret = max(ret, go(idx + 1, 0));
	

	return ret;
}
int main(void)
{
	
	cin >> glassCnt;
	
	for (int i = 0; i < glassCnt; ++i)
		cin >> glass[i];
	
	memset(cache, -1, sizeof(cache));
	cout << go(0,0) << '\n';
	return 0;
}