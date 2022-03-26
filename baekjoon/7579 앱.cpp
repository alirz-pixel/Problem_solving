/* 2022-03-26  14:08 
백준 7579번  ||  골드 3
https://www.acmicpc.net/problem/7559

분야 : [ 다이나믹 프로그래밍, 배낭 문제 ]

================================
문제를 제대로 읽지않아 뒤로 1칸 후진해야 할 것을
2칸 후진해야 된다 생각하여 꽤나 오래걸리게 되었다..
================================

시작시간 : **:**
종료시간 : **:**   ||  [ 시도횟수 : *회  |  걸린시간 : **분 ]
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct App {
	int memory;
	int cost;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<App> app(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> app[i].memory;
	}

	int max_cost = 0;
	for (int i = 1; i <= n; i++) {
		cin >> app[i].cost;
		max_cost += app[i].cost;
	}

	int ans = INT_MAX;
	vector<vector<int>> arr(n + 1, vector<int>(max_cost + 1));
	for (int item = 1; item <= n; item++) {
		for (int cost = 0; cost <= max_cost; cost++) {
			arr[item][cost] = arr[item - 1][cost];
			if (app[item].cost <= cost) {
				arr[item][cost] = max(arr[item][cost], app[item].memory + arr[item - 1][cost - app[item].cost]);
			}

			if (arr[item][cost] >= m) {
				ans = min(ans, cost);
			}
		}
	}

	cout << ans;

	return 0;
}
/*
2022:03:26  14:01
배낭문제 - k냅색
*/