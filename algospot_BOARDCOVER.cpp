#include <iostream>
#include <array>
using namespace std;

array<array<char, 20>, 20> board;

void cinboard(int H, int W);
int method(int H, int W, int loci, int locj, int count);

int main()
{
	int C, H, W;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> H >> W;
		cinboard(H, W); //게임판 입력

		cout << method(H, W, 0, 0, 0) << "\n"; //방법의 수 출력
	}
}

void cinboard(int H, int W)
{
	for (int i{ 0 }; i < H; i++)
	{
		for (int j{ 0 }; j < W; j++)
		{
			cin >> board[i][j];
		}
	}
}

int method(int H, int W, int loci, int locj, int count)
{
	while (board[loci][locj] == '#') //내가 보고자 하는 게임판의 좌표 이동
	{
		locj++;
		if (locj == W)
		{
			loci++;
			locj = 0;
		}
		if (loci == H) return count + 1;
	}

	//게임판을 덮는 12가지 경우의 수 탐색, 재귀
	if (loci != 0 && locj != 0)
	{
		if (board[loci - 1][locj] == '.' && board[loci][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci - 1][locj] = '#', board[loci][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci - 1][locj] = '.', board[loci][locj - 1] = '.';
		}
		if (board[loci - 1][locj] == '.' && board[loci - 1][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci - 1][locj] = '#', board[loci - 1][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci - 1][locj] = '.', board[loci - 1][locj - 1] = '.';
		}
		if (board[loci][locj - 1] == '.' && board[loci - 1][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci][locj - 1] = '#', board[loci - 1][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci][locj - 1] = '.', board[loci - 1][locj - 1] = '.';
		}
	}
	if (loci != 0 && locj != W - 1)
	{
		if (board[loci - 1][locj] == '.' && board[loci][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci - 1][locj] = '#', board[loci][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci - 1][locj] = '.', board[loci][locj + 1] = '.';
		}
		if (board[loci - 1][locj] == '.' && board[loci - 1][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci - 1][locj] = '#', board[loci - 1][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci - 1][locj] = '.', board[loci - 1][locj + 1] = '.';
		}
		if (board[loci][locj + 1] == '.' && board[loci - 1][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci][locj + 1] = '#', board[loci - 1][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci][locj + 1] = '.', board[loci - 1][locj + 1] = '.';
		}
	}
	if (loci != H - 1 && locj != 0)
	{
		if (board[loci + 1][locj] == '.' && board[loci][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci + 1][locj] = '#', board[loci][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci + 1][locj] = '.', board[loci][locj - 1] = '.';
		}
		if (board[loci + 1][locj] == '.' && board[loci + 1][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci + 1][locj] = '#', board[loci + 1][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci + 1][locj] = '.', board[loci + 1][locj - 1] = '.';
		}
		if (board[loci][locj - 1] == '.' && board[loci + 1][locj - 1] == '.')
		{
			board[loci][locj] = '#', board[loci][locj - 1] = '#', board[loci + 1][locj - 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci][locj - 1] = '.', board[loci + 1][locj - 1] = '.';
		}
	}
	if (loci != H - 1 && locj != W - 1)
	{
		if (board[loci + 1][locj] == '.' && board[loci][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci + 1][locj] = '#', board[loci][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci + 1][locj] = '.', board[loci][locj + 1] = '.';
		}
		if (board[loci + 1][locj] == '.' && board[loci + 1][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci + 1][locj] = '#', board[loci + 1][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci + 1][locj] = '.', board[loci + 1][locj + 1] = '.';
		}
		if (board[loci][locj + 1] == '.' && board[loci + 1][locj + 1] == '.')
		{
			board[loci][locj] = '#', board[loci][locj + 1] = '#', board[loci + 1][locj + 1] = '#';
			count = method(H, W, loci, locj, count);
			board[loci][locj] = '.', board[loci][locj + 1] = '.', board[loci + 1][locj + 1] = '.';
		}
	}

	return count;
}