#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int map[10][10];
int check[10][10];
int sizet, honeyBottle, cap;

int max_honey;
void getMaxProfit(int x, int y, int cnt, int sumProfit, int sumPowProfit)
{
	if (sumProfit > cap) return;
	if (cnt == honeyBottle)
	{
		max_honey = max(max_honey, sumPowProfit);
		return;
	}


	getMaxProfit(x, y + 1, cnt + 1, sumProfit + map[x][y], sumPowProfit + pow(map[x][y], 2));
	getMaxProfit(x, y + 1, cnt + 1, sumProfit, sumPowProfit);
}
int solve(int x, int y) {

	for (int i = 0; i < honeyBottle; i++) {
		check[x][y + i] = true;
	}
	

	getMaxProfit(x, y, 0, 0, 0);
	int cost_A = max_honey;
	int cost_B = 0;

	for (int i = 0; i < sizet; i++) {
		for (int j = 0; j < sizet - honeyBottle + 1; j++) {
			if (check[i][j]==0) {
				max_honey = 0;
				getMaxProfit(i, j, 0, 0, 0);
				cost_B = max(cost_B, max_honey);
			}
		}
	}
	return cost_A + cost_B;
}
int main(void)
{
	int TC;
	cin >> TC;
	for (int test_case = 1; test_case <= TC; test_case++)
	{
	
		cin >> sizet >> honeyBottle >> cap;
		
		//∏ √ ±‚»≠
		for (int i = 0; i < 10; ++i) 
		{
			for (int j = 0; j < 10; ++j)
			{
				map[i][j] = 0;
				check[i][j] = 0;
			}
		}

		for (int i = 0; i < sizet; ++i)
			for (int j = 0; j < sizet; ++j)
				cin >> map[i][j];
		
		int ans = 0;
		for (int i = 0; i < sizet; ++i)
		{
			for (int j = 0; j < sizet - honeyBottle + 1; ++j)
			{
				max_honey = 0;
				ans = max(ans, solve(i, j));
			}
		}

		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}