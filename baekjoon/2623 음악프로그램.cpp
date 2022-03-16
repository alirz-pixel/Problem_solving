/* 2022-03-16  09:32
백준 2623번 음악프로그램  ||  골드 2
https://www.acmicpc.net/problem/2623

분야 : [ 위상정렬 ]


==============================
위상 정렬 문제를 많이 풀어보지 않아
해당 문제가 위상 정렬을 이용해서 풀어야 되는 문제인지 파악하는데 시간이 오래걸렸다..
==============================


시작시간 : 08:40
종료시간 : 09:22       [시도횟수 : 1회  |  걸린시간 : 40분]
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<int> in_degree;

void solve(int N) {
	queue<int> empty_in_degree;
	queue<int> ans;

	// 진입차수가 0인 것들 큐에 넣기
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) {
			empty_in_degree.push(i);
			cnt++;
		}
	}

	while (!empty_in_degree.empty()) {
		int front = empty_in_degree.front();
		ans.push(front);
		empty_in_degree.pop();

		for (auto i : graph[front]) {
			in_degree[i]--;

			if (in_degree[i] == 0) {
				empty_in_degree.push(i);
				cnt++;
			}
		}
	}

	if (N == cnt) {
		while (!ans.empty()) {
			cout << ans.front() << "\n";
			ans.pop();
		}
	}
	else {
		cout << 0;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	graph = vector<vector<int>>(N + 1);
	in_degree = vector<int>(N + 1);

	for (int i = 0; i < M; i++) {
		int singer_cnt;
		cin >> singer_cnt;

		int pre, cur;
		cin >> pre;
		for (int j = 1; j < singer_cnt; j++) {
			cin >> cur;

			graph[pre].push_back(cur);
			in_degree[cur]++;

			pre = cur;
		}
	}

	solve(N);

	return 0;
}