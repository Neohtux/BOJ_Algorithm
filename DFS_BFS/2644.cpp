/*#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N; //Node Count;
int from, to;

bool check[101];
void bfs(int Start_Node, vector<vector<int>> &v);
int list_count;
queue<pair<int,int>> q;
int main(void)
{
	cin >> N;
	vector<vector<int>> v(N+1);

	cin >> from >> to;
	cin >> list_count;
	
	int input_a, input_b;

	for (int i = 0; i < list_count; ++i)
	{
		cin >> input_a >> input_b;
		v[input_a].push_back(input_b);
		v[input_b].push_back(input_a);
	}
	 
	
	q.push(make_pair(from,0));
	check[from] = true;

	bfs(from,v);

	return 0;
}

void bfs(int Start_Node, vector<vector<int>> &v)
{
	while (!q.empty())
	{
		int node = q.front().first;
		int dist = q.front().second;

		if (node == to)
		{
			cout << dist << '\n';
			return;
		}
		q.pop();
		for (int i = 0; i < v[node].size(); ++i)
		{
			int next_node = v[node][i];

			if (check[next_node] == false)
			{
				check[next_node] = true;
				q.push(make_pair(next_node, dist + 1));
			}
		}
	}
	cout << -1 << '\n';
	return;
}
*/