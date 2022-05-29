#include <iostream>
#include <array>
#include <climits>
using namespace std;

array<int, 16> Clock;
array<array<bool, 16>, 10> push
{
	{
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
	}
};

void cinClock();
int rotateClock(int swtch, int count, int min);

int main()
{
	int C, answer;

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> C;
	for (int i{ 0 }; i < C; i++)
	{
		cinClock();
		answer = rotateClock(0, 0, INT_MAX);
		if (answer == INT_MAX) cout << "-1\n";
		else cout << answer << "\n";
	}
}

void cinClock()
{
	for (int i{ 0 }; i < 16; i++)
	{
		cin >> Clock[i];
	}
}

int rotateClock(int swtch, int count, int min)
{
	if (swtch == 10)
	{
		for (int i{ 0 }; i < 16; i++)
		{
			if (Clock[i] != 12) return min;
			if (i == 15)
			{
				if (min > count) min = count;
				return min;
			}
		}
	}

	min = rotateClock(swtch + 1, count, min);
	for (int i{ 0 }; i < 16; i++)
	{
		if (push[swtch][i]) Clock[i] += 3;
		if (Clock[i] == 15) Clock[i] = 3;
	}
	min = rotateClock(swtch + 1, count + 1, min);
	for (int i{ 0 }; i < 16; i++)
	{
		if (push[swtch][i]) Clock[i] += 3;
		if (Clock[i] == 15) Clock[i] = 3;
	}
	min = rotateClock(swtch + 1, count + 2, min);
	for (int i{ 0 }; i < 16; i++)
	{
		if (push[swtch][i]) Clock[i] += 3;
		if (Clock[i] == 15) Clock[i] = 3;
	}
	min = rotateClock(swtch + 1, count + 3, min);
	for (int i{ 0 }; i < 16; i++)
	{
		if (push[swtch][i]) Clock[i] += 3;
		if (Clock[i] == 15) Clock[i] = 3;
	}

	return min;
}