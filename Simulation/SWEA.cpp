#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int N = 0, K = 0;
int ConversionHD(string str)
{
	int _start = N-1;
	long long _sum = 0;
	
	for (int i = 0; i < str.size(); ++i)
	{
		long long fow_value = 16;
		int tmp = 0;
		int tmp_fow = 1;
		//1~9일때
		if (str[i] >= 48 && str[i] <= 57)
			tmp = str[i] - '0';
		else//A~F일때 
			tmp = str[i] - '7';
		
		for (int k = 0; k < _start; ++k)
			tmp_fow *= fow_value;

		fow_value = tmp * tmp_fow;
		_sum += fow_value;

		_start--;

	}
	return _sum;
}
long long Solve(vector<char> v)
{
	set<int,greater<int>> us;
	for (int rotCnt = 0; rotCnt < N; ++rotCnt)
	{
		//N-char
		string tmp = "";
		for (int i = 0; i < v.size(); ++i)
		{
			if ( i != 0 && i % N == 0)
			{
				//Conversion Hex -> Decimal
				us.insert(ConversionHD(tmp));
				tmp = "";
			}
			tmp += v[i];
		}
		//끝문자 Conversion
		us.insert(ConversionHD(tmp));
		//
		
		//Rotate
		char _end = v.back();
		for (int i = v.size() - 2; i >= 0; i--)
		{
			v[i + 1] = v[i];
		}
		v[0] = _end;
	}
	
	set<int>::iterator iter;
	long long idx = 0;
	for (iter = us.begin(); iter != us.end(); ++iter,++idx)
	{
		if (idx == K-1)
		{
			idx = *iter;
			break;
		}
	}
	
	return idx;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> N >> K;
		cin >> str;
		vector<char> v;
		N = N / 4;
		for (int i = 0; i < str.size(); ++i)
		{
			v.push_back(str[i]);
		}
		cout << "#"<<test_case<<" "<<Solve(v)<<'\n';
	}
	return 0;
}