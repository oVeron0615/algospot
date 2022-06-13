#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int c;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> c;
	for (int i{ 0 }; i < c; i++)
	{
		int n;
		priority_queue<int, vector<int>, greater<int>> strlen;

		cin >> n;
		for (int j{ 0 }; j < n; j++)
		{
			int len;
			cin >> len;
			strlen.push(len);
		}

		int cost{ 0 };
		while (strlen.size() != 1)
		{
			int min1{ strlen.top() };
			strlen.pop();
			int min2{ strlen.top() };
			strlen.pop();
			cost += min1 + min2;
			strlen.push(min1 + min2);
		}

		cout << cost << "\n";
	}
}