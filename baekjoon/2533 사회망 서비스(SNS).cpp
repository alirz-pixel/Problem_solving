/* 2022-03-05  06:04
백준 2533번 사회망 서비스(SNS) || 골드 3
https://www.acmicpc.net/problem/2533 

분야 : [dp, tree, dp in tree]


시작시간 : 04:53
종료시간 : 06:05       [시도횟수 : 1회  |  걸린시간 : 1시간 12분]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;
int root = 0;

// 1 : 얼리 아답터
// 0 : no 얼리 아답터
void solve(int parent) {
	// 자식이 없는 경우
	if (graph[parent].size() == 1 && parent != root) {
		dp[parent][1] = 1;
		dp[parent][0] = 0;

		return;
	}
	
	for (auto i : graph[parent]) {
		if (visited[i]) {
			continue;
		}

		visited[i] = true;
		solve(i);

		dp[parent][1] += min(dp[i][1], dp[i][0]);
		dp[parent][0] += dp[i][1];
	}
	dp[parent][1] += 1;

	return;
}

int main() {
	int N, u, v;
	cin >> N;

	dp = vector<vector<int>>(N, vector<int>(2));
	graph = vector<vector<int>>(N);
	visited = vector<bool>(N);
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		u--; v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	visited[root] = true;
	solve(root);

	cout << min(dp[root][0], dp[root][1]);

	return 0;
}
