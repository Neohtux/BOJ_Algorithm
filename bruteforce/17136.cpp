#include<iostream>
#include<vector>
using namespace std;

bool Is_stick_paper(int paper_size,int x,int);
void go(int x, int y, int attached_cnt);
void update_paper(bool ON_OFF, int x, int y, int paper_size);

int arr[10][10];
int check[10][10]; //
int num_counts[7] = { 0,5,5,5,5,5,0 }; //����� ���� ���� ����

int one_count; //���̿� 1�� ����
int min_ans = 1e9;

bool isAble_Stick = false;
int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j])
			{
				one_count += 1;
			}
		}
	}
	if (one_count == 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	

	go(0,0,0);
	if (isAble_Stick) //��� ���̴°��� ��������
	{
		cout << min_ans << '\n';
	}
	else cout << -1 << '\n'; //�ƴ϶�� -1 ���
	
	return 0;
}
void go(int x,int y, int attached_cnt)
{
	if (one_count == 0) //�� ���� ��� one_count�� �ʱ� 1�� ����
	{
		isAble_Stick = true;
		if (min_ans > attached_cnt)
			min_ans = attached_cnt;
		return;
	}
	
	int xn = 0, yn = 0; //���� ������ �õ��غ� xn, yn ��ǥ
	
	//���� �����ؾ��� ���� ã����.
	for (int i = 0; i < 10; ++i)
	{
		bool isout = false;
		for (int j = 0; j < 10; ++j)
		{
			if (arr[i][j] == 1 && check[i][j]==false) //1�̿��� �ٿ����ϰ�, ��ġ�� �ʴ°�.
			{
				xn = i;
				yn = j;
				isout = true;
				break;
			}
		}
		if (isout) break;
	}

	// 1~5��������� �ٿ���
	for (int paper_size = 1; paper_size <=5; paper_size++)
	{
		if (Is_stick_paper(paper_size, xn, yn)) //�ش� �������� ���̸� xn,yn�� ���� �� �ִ���
		{
			num_counts[paper_size] -= 1; // ����� ���� ���� ���� [0,5,5,5,5,5,0]
			update_paper(true, xn, yn, paper_size); // check�迭�� true�� ������ ���̱�.
			one_count -= (paper_size*paper_size); // one_count ==0 : ��� ���ΰ��

			go(xn, yn, attached_cnt + 1);

			num_counts[paper_size] += 1; //�ѹ�
			update_paper(false, xn, yn, paper_size);  //�ѹ�
			one_count += (paper_size*paper_size); //��� ������ŭ �ѹ�

		}
		
	}
	return;
}
void update_paper(bool ON_OFF, int x, int y, int paper_size)
{
	for (int i = 0; i < paper_size; ++i)
	{
		for (int j = 0; j < paper_size; ++j)
		{
			check[x+i][y+j] = ON_OFF;
		}
	}
}
bool Is_stick_paper(int paper_size,int x,int y)
{
	if (num_counts[paper_size] == 0) return false; //�ش� �������� ���̰� ���ڶ����
	if (x + paper_size > 10 || y + paper_size > 10) return false; //���̴� ��ƼĿ ����� ���� ����� �Ѿ�°��
	int xn = x;
	int yn = y;

	for (int i = 0; i < paper_size; ++i)
	{
		for (int j = 0; j < paper_size; ++j)
		{
			if (arr[x+i][y+j] == 0) return false; // 1�� ĥ���� ���� ������.
			if (check[x+i][y+j] == true) return false; //��ƼĿ�� ��ĥ��
		}
			
	}

	return true;
}