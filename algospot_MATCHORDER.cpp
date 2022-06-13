#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> russia, korea;
	int C, N;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cin >> N;
		for (int i{ 0 }; i < N; i++)
		{
			int score;
			cin >> score;
			russia.push_back(score);
		}
		for (int i{ 0 }; i < N; i++)
		{
			int score;
			cin >> score;
			korea.push_back(score);
		}

		sort(russia.begin(), russia.end());
		sort(korea.begin(), korea.end());

		int russialoc{ 0 }, win{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			if (korea[i] >= russia[russialoc])
			{
				win++;
				russialoc++;
			}
		}

		cout << win << "\n";
		russia.clear();
		korea.clear();
	}
}