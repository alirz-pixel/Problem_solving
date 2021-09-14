/*  2021-09-11  4:28
백준 2096번 내려가기  ||  골드4
https://www.acmicpc.net/problem/2156




시작시간 : *:** 
종료시간 : *:**     제출시도 : 3회  ||  
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<int> input(3);
	vector<pair<int, int>> dp(3), temp(3);

	// solve();
	for (int i = 0; i < n; i++)
	{
		for (auto &j : input)
			cin >> j;

		temp[0].first = max(dp[0].first, dp[1].first) + input[0];
		temp[0].second = min(dp[0].second, dp[1].second) + input[0];

		temp[1].first = max(dp[0].first, max(dp[1].first, dp[2].first)) + input[1];
		temp[1].second = min(dp[0].second, min(dp[1].second, dp[2].second)) + input[1];

		temp[2].first = max(dp[1].first, dp[2].first) + input[2];
		temp[2].second = min(dp[1].second, dp[2].second) + input[2];

		for (int j = 0; j < 3; j++)
			dp[j] = temp[j];
	}

	cout << max(dp[0].first, max(dp[1].first, dp[2].first)) << " " << min(dp[0].second, min(dp[1].second, dp[2].second));

	return 0;
}