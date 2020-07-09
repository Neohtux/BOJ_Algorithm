#include<iostream>
#include<stack>
#include<string>

using namespace std;

void solve(stack<char> &str_stack);
//abc,ABC,0~9
string target; //1~36
string removed; //1~36 

int main(void)
{
	cin >> target >> removed;

	stack<char> result_string;
	solve(result_string);
	
	if (removed.length() == 1)
	{
		string ans;
		for (int i = 0; i < target.size(); ++i)
		{
			if (target[i] != removed[0])
				ans += target[i];
		}
		if (ans.size() == 0)
		{
			cout << "FRULA" << '\n';
			return 0;
		}
		cout << ans << '\n';
		return 0;
	}
	if (result_string.empty())
	{
		cout << "FRULA" << '\n';
	}
	else
	{
		stack<char> a;
		int length = result_string.size();
		for (int i = 0; i < length; ++i)
		{
			a.push(result_string.top());
			result_string.pop();
		}
		string ans;
		for (int i = 0; i < length; ++i)
		{
			ans += a.top();
			a.pop();
		}
	
	
		cout << ans << '\n';
	}
	
	return 0;
}

void solve(stack<char> &str_stack)
{
	
	stack <pair<int,int>> s_removed;
	
	for (int i = 0; i < target.size(); ++i)
	{
		str_stack.push(target[i]);
		if (target[i] == removed[0])
		{
			s_removed.push(make_pair(i, 0));
		}
		else
		{
			//c  c  4 
			//c  4     (2)
			//   c  4  (3)
			if (!s_removed.empty())//(2)
			{
				int removed_idx = s_removed.top().second;

				if (target[i] == removed[removed_idx + 1]) //(3)
				{
					s_removed.push(make_pair(i, removed_idx + 1));
					
					//이어진 문자열을 찾은 경우.
					if (removed_idx + 1 == removed.size() - 1)
					{
						for (int i = 0; i < removed.size(); ++i)
						{
							s_removed.pop();
							str_stack.pop();
						}
					}
				}
				else
				{
					while (!s_removed.empty())
						s_removed.pop();
				}

			}
		
			
		}
		
	}
}