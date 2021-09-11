/*  2021-09-11  10:52
백준 11048번 이동하기  ||  실버1
https://www.acmicpc.net/problem/11048



그냥 간단하게 dp 문제로다가 max값을 체크하면서 내려가면 된다.



시작시간 : 10:52
종료시간 : 10:57     제출시도 : 1회  ||  걸린시간 : 5분
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;

	vector<vector<int>> maze(n, vector<int>(m));
	for (auto &i : maze)
		for (auto &j : i)
			cin >> j;

	
	// solve();
	vector<vector<int>> dp(n+1, vector<int>(m+1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1])) + maze[i-1][j-1];


	cout << dp[n][m];

	return 0;
}