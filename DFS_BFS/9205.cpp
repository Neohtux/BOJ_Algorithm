#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;

bool check[101];
queue<pair<int, int>> q;
vector<pair<int, int>> locations;
int T; // test case
void go_festival();
bool isfind = false;
int main(void)
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		int x = 0, y = 0;
		for (int i = 0; i < N + 2; ++i)
		{
			cin >> x >> y;
			locations.push_back(make_pair(x, y));
		}
		q.push(make_pair(locations[0].first,locations[0].second));
		check[0] = true;
		go_festival();
		if (!isfind)
		{
			cout << "sad" << '\n';
		}
		isfind = false;
		while (!locations.empty()) { locations.pop_back(); }
		while (!q.empty()) { q.pop();}
		for (int i = 0; i < N+2; ++i)
			check[i] = false;
		
	}
	
	return 0;
}

void go_festival()
{
	int RockFestival_pos = locations.size()-1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == locations[RockFestival_pos].first && y == locations[RockFestival_pos].second)
		{
			cout << "happy" << '\n';
			isfind = true;
			return;
		}

		for (int i = 1; i < locations.size(); ++i)
		{
			int xn = locations[i].first;
			int yn = locations[i].second;

			
			int tmp_xn = xn - x;
			int tmp_yn = yn - y;

			if (tmp_xn < 0) tmp_xn = -tmp_xn;
			if (tmp_yn < 0) tmp_yn = -tmp_yn;

			int distance = tmp_xn + tmp_yn;

			if (check[i] == false && ((distance/50)-20 <= 0))
			{
				check[i] = true;
				q.push(make_pair(xn, yn));
			}
		}
	}

	
}