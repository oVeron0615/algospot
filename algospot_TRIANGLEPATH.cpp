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
		cinTriangle(n); //삼각형 입력
		max_path_sum(0, 0, n); //최대 합 찾기
		cout << triangle[0][0] << "\n"; //출력
	}
}

void cinTriangle(int n)
{
	for (int i{ 0 }; i < n; i++)
	{
		for (int j{ 0 }; j <= i; j++)
		{
			cin >> triangle[i][j];
			triangle_memo[i][j] = true; //전부 true로 초기화
		}
	}
}

void max_path_sum(int x, int y, int n)
{
	if (x == n - 1) return; //마지막 층이면 리턴

	if (triangle_memo[x + 1][y]) //참이면 재귀, 거짓이면 무시
	{
		max_path_sum(x + 1, y, n); //아래
		triangle_memo[x + 1][y] = false;
	}
	if (triangle_memo[x + 1][y + 1])
	{
		max_path_sum(x + 1, y + 1, n); //아래 - 오른쪽
		triangle_memo[x + 1][y + 1] = false;
	}

	int plus = triangle[x + 1][y] > triangle[x + 1][y + 1] 
		? triangle[x + 1][y] : triangle[x + 1][y + 1];
	triangle[x][y] += plus; //아래와 오른쪽 아래 중 큰 것을 더함
}