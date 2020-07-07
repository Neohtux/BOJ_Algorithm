#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> preprocessing(string s);
vector<int> kmp(string s, string p)
{
	vector<int> fail = preprocessing(p);

	vector<int> ans;
	int s_length = s.size();
	int p_length = p.size();
	int j = 0;

	// aaabbc
	// 01abb
	for (int i = 0; i < s_length; ++i)
	{
		while (j > 0 && s[i] != p[j])
		{
			j = fail[j - 1];
		}

		if (s[i] == p[j]) // ���ڿ� s�� i��° ���ڶ� , ���ڿ� p�� j��° ���ڶ� ������
		{
			//������ ����?
			if (j == p_length - 1)
			{
				ans.push_back(i - j+1);
				j = fail[j]; //������ ��� ã�ƾ� �ϱ� ������ �ٽ� 19��°�ٷ� ��������
			}
			else j += 1;
		}

	
	}
	return ans;

}
vector<int> preprocessing(string s)
{
	vector<int> f_r(s.size());
	int j = 0;

	f_r[0] = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		//s[i] ��° �� s[j] char�� ������ ��
		//���� ���� �ʴٸ� j-1��°���� (<- ������ ��� �ؼ� �˻�)

		while (j > 0 && s[i] != s[j])
		{
			j = f_r[j - 1]; // 
		}

		if (s[i] == s[j])
		{
			f_r[i] = j + 1;
			j += 1;
		}
		else //��� ��ġ ����. 
		{
			f_r[i] = 0;
		}
	}
	
	return f_r;
}
int main(void)
{
	//string s = "ABC ABCDAB ABCDABCDABDE";
	string s;
	string p;

	getline(cin,s);
	getline(cin, p);
	//getline(p);

	//vector<int> ans = preprocessing(s);
	vector<int> ans = kmp(s, p);

	cout << ans.size() << '\n';
	
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';


	return 0;
}
