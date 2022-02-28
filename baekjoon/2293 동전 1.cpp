/* 2022-02-28  18:53
백준 2293번 동전 1 || 골드 5
https://www.acmicpc.net/problem/45649


분야 : [DP]


시작시간 : **:**
종료시간 : **:**
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N, K;
	cin >> N >> K;

	vector<int> coins(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> coins[i];
	}


	vector<int> dp(K + 1);
	dp[0] = 1;

	for (int c_index = 1; c_index <= N; c_index++) {
		for (int k_num = 0; k_num <= K; k_num++) {
			if (coins[c_index] <= k_num) {
				dp[k_num] += dp[k_num - coins[c_index]];
			}
		}
	}

	cout << dp[K];

	return 0;
}