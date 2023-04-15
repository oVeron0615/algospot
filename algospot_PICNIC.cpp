#include <iostream>
#include <vector>
#include <array>
using namespace std;

array<vector<int>, 10> frienddual;
array<bool, 10> studentmatch{};

void cinfrienddual(int m);
int match(int loc, int count, int n);
void clearfrienddual();

int main()
{
	int C, n, m;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		int n, m;
		cin >> n >> m;

		cinfrienddual(m);
		cout << match(0, 0, n) << "\n";
		clearfrienddual();
	}
}

//¦���� �� �ִ� ģ�� �� vector�� �ֱ�
void cinfrienddual(int m)
{
	int friend1, friend2;

	for (int i{ 0 }; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		int friend1 = a < b ? a : b;
		int friend2 = a > b ? a : b;
		frienddual[friend1].push_back(friend2);
	}
}

//bruteforce�� ģ�� ���� ���� Ž��
int match(int loc, int count, int n)
{
	if (loc == n)
	{
		count++;
		return count;
	}
	while (studentmatch[loc])
	{
		loc++;
		if (loc == n)
		{
			count++;
			return count;
		}
	}

	studentmatch[loc] = true;
	for (int i{ 0 }; i < frienddual[loc].size(); i++)
	{
		if (studentmatch[frienddual[loc][i]]) continue;
		else
		{
			studentmatch[frienddual[loc][i]] = true;
			count = match(loc + 1, count, n);
			studentmatch[frienddual[loc][i]] = false;
		}
	}
	studentmatch[loc] = false;

	return count;
}

//ģ�� �� ���� vector ����
void clearfrienddual()
{
	for (int i{ 0 }; i < 10; i++) frienddual[i].clear();
}