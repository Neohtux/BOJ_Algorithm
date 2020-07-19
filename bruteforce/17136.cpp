#include<iostream>
#include<vector>
using namespace std;

bool Is_stick_paper(int paper_size,int x,int);
void go(int x, int y, int attached_cnt);
void update_paper(bool ON_OFF, int x, int y, int paper_size);

int arr[10][10];
int check[10][10]; //
int num_counts[7] = { 0,5,5,5,5,5,0 }; //사이즈별 남은 종이 갯수

int one_count; //종이에 1의 갯수
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
	if (isAble_Stick) //모두 붙이는것이 가능한지
	{
		cout << min_ans << '\n';
	}
	else cout << -1 << '\n'; //아니라면 -1 출력
	
	return 0;
}
void go(int x,int y, int attached_cnt)
{
	if (one_count == 0) //다 붙인 경우 one_count는 초기 1의 갯수
	{
		isAble_Stick = true;
		if (min_ans > attached_cnt)
			min_ans = attached_cnt;
		return;
	}
	
	int xn = 0, yn = 0; //다음 부착을 시도해볼 xn, yn 좌표
	
	//다음 부착해야할 곳을 찾는중.
	for (int i = 0; i < 10; ++i)
	{
		bool isout = false;
		for (int j = 0; j < 10; ++j)
		{
			if (arr[i][j] == 1 && check[i][j]==false) //1이여서 붙여아하고, 겹치지 않는곳.
			{
				xn = i;
				yn = j;
				isout = true;
				break;
			}
		}
		if (isout) break;
	}

	// 1~5사이즈까지 붙여봄
	for (int paper_size = 1; paper_size <=5; paper_size++)
	{
		if (Is_stick_paper(paper_size, xn, yn)) //해당 사이즈의 종이를 xn,yn에 붙일 수 있는지
		{
			num_counts[paper_size] -= 1; // 사이즈별 남은 종이 갯수 [0,5,5,5,5,5,0]
			update_paper(true, xn, yn, paper_size); // check배열에 true로 색종이 붙이기.
			one_count -= (paper_size*paper_size); // one_count ==0 : 모두 붙인경우

			go(xn, yn, attached_cnt + 1);

			num_counts[paper_size] += 1; //롤백
			update_paper(false, xn, yn, paper_size);  //롤백
			one_count += (paper_size*paper_size); //떼어낸 갯수만큼 롤백

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
	if (num_counts[paper_size] == 0) return false; //해당 사이즈의 종이가 모자란경우
	if (x + paper_size > 10 || y + paper_size > 10) return false; //붙이는 스티커 사이즈가 종이 사이즈를 넘어가는경우
	int xn = x;
	int yn = y;

	for (int i = 0; i < paper_size; ++i)
	{
		for (int j = 0; j < paper_size; ++j)
		{
			if (arr[x+i][y+j] == 0) return false; // 1이 칠해져 있지 않은곳.
			if (check[x+i][y+j] == true) return false; //스티커가 겹칠때
		}
			
	}

	return true;
}