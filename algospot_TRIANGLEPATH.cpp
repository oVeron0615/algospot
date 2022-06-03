#include <iostream>
#include <array>
using namespace std;

array<array<int, 100>, 100> triangle;
array<array<bool, 100>, 100> triangle_memo;

void cinTriangle(int n);
void max_path_sum(int x, int y, int n);

int main()
{
	int C, n;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> n;
		cinTriangle(n); //�ﰢ�� �Է�
		max_path_sum(0, 0, n); //�ִ� �� ã��
		cout << triangle[0][0] << "\n"; //���
	}
}

void cinTriangle(int n)
{
	for (int i{ 0 }; i < n; i++)
	{
		for (int j{ 0 }; j <= i; j++)
		{
			cin >> triangle[i][j];
			triangle_memo[i][j] = true; //���� true�� �ʱ�ȭ
		}
	}
}

void max_path_sum(int x, int y, int n)
{
	if (x == n - 1) return; //������ ���̸� ����

	if (triangle_memo[x + 1][y]) //���̸� ���, �����̸� ����
	{
		max_path_sum(x + 1, y, n); //�Ʒ�
		triangle_memo[x + 1][y] = false;
	}
	if (triangle_memo[x + 1][y + 1])
	{
		max_path_sum(x + 1, y + 1, n); //�Ʒ� - ������
		triangle_memo[x + 1][y + 1] = false;
	}

	int plus = triangle[x + 1][y] > triangle[x + 1][y + 1] 
		? triangle[x + 1][y] : triangle[x + 1][y + 1];
	triangle[x][y] += plus; //�Ʒ��� ������ �Ʒ� �� ū ���� ����
}