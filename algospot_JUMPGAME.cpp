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
		cingrid(n); //���� �Է�
		check_reach_end(0, 0, n); //������ ������ �� �ִ� �� Ȯ��
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
	if (grid[x][y] == 0) //���� �����ϸ� yes���, pass�� true�� ����� ����
	{
		cout << "YES\n";
		pass = true;
		return;
	}
	if (grid[x][y] == -1) return; //-1�̸� �̹� Ž���� ���̹Ƿ� ����

	int move = grid[x][y]; //�������� �� ĭ��
	if (x + move < n)
	{
		check_reach_end(x + move, y, n); //�Ʒ������� �̵�
		if (pass) return; //���� ���������� ����
	}
	if (y + move < n)
	{
		check_reach_end(x, y + move, n); //���������� �̵�
		if (pass) return; //���� ���������� ����
	}

	grid[x][y] = -1; //Ž�� �� �ϸ� -1�� �ٲ���
	if (grid[0][0] == -1) cout << "NO\n"; //����ĭ�� -1�̸� no���
}