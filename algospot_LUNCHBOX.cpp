#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> EaW;
	vector<int> eat_and_warm;
	array<array<int, 2>, 10000> warm_and_eat;
	int C;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		int n;
		cin >> n;

		for (int j{ 0 }; j < n; j++) cin >> warm_and_eat[j][0];
		for (int j{ 0 }; j < n; j++) cin >> warm_and_eat[j][1];
		for (int j{ 0 }; j < n; j++)
		{
			eat_and_warm.push_back(warm_and_eat[j][1]);
			eat_and_warm.push_back(warm_and_eat[j][0]);
			EaW.push_back(eat_and_warm);
			eat_and_warm.clear();
		}
		sort(EaW.begin(), EaW.end());

		int warmtime{ 0 }, maxtime{ 0 };
		for (int j{ n - 1 }; j >= 0; j--)
		{
			warmtime += EaW[j][1];
			if (maxtime < warmtime + EaW[j][0])
				maxtime = warmtime + EaW[j][0];
		}

		cout << maxtime << "\n";
	}
}