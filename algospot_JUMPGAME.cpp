#include <iostream>
#include <array>
using namespace std;

array<array<int, 100>, 100> grid;

void cingrid(int n);
void check_reach_end(int x, int y, int n);
bool pass{ false };

int main()
{
	int C, n;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> n;
		cingrid(n); //격자 입력
		check_reach_end(0, 0, n); //끝점에 도달할 수 있는 지 확인
		pass = false;
	}
}

void cingrid(int n)
{
	for (int i{ 0 }; i < n; i++)
	{
		for (int j{ 0 }; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
}

void check_reach_end(int x, int y, int n)
{
	if (grid[x][y] == 0) //끝에 도달하면 yes출력, pass를 true로 만들고 리턴
	{
		cout << "YES\n";
		pass = true;
		return;
	}
	if (grid[x][y] == -1) return; //-1이면 이미 탐색한 곳이므로 리턴

	int move = grid[x][y]; //움직여야 할 칸수
	if (x + move < n)
	{
		check_reach_end(x + move, y, n); //아래쪽으로 이동
		if (pass) return; //끝에 도달했으면 리턴
	}
	if (y + move < n)
	{
		check_reach_end(x, y + move, n); //오른쪽으로 이동
		if (pass) return; //끝에 도달했으면 리턴
	}

	grid[x][y] = -1; //탐색 다 하면 -1로 바꿔줌
	if (grid[0][0] == -1) cout << "NO\n"; //시작칸이 -1이면 no출력
}