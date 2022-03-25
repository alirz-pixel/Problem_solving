/*  2022-03-25  16:37
백준 2310 어드밴처 게임  ||  골드5
https://www.acmicpc.net/problem/2310


분야 : [DFS, BFS, graph]

visited 처리를 실수하여 디버깅 하는데 오래걸림 +
제출 1회 실패함. (원인 : 시간초과)

시작시간 : 15:54
풀이구상 : 16:38      제출시도 : 2회  ||  걸린시간 : 44분
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
	int num;
	int money;
};

bool solve(int n) {
	vector<pair<pair<char, int>, vector<int>>> room(n + 1);
	for (int index = 1; index <= n; index++) {
		auto &i = room[index];
		cin >> i.first.first >> i.first.second;

		while (1)
		{
			int input;
			cin >> input;

			if (input == 0) {
				break;
			}

			i.second.push_back(input);
		}
	}


	vector<vector<bool>> v(n + 1, vector<bool>(501));
	queue<info> q;

	v[1][room[1].first.second] = true;
	q.push({ 1, room[1].first.second });

	bool is_goal = false;
	while (!q.empty()) {
		info front = q.front();
		q.pop();

		if (front.num == n) {
			is_goal = true;
			break;
		}

		for (auto nn : room[front.num].second) {
			if (room[nn].first.first == 'E') {
				if (v[nn][front.money] == true) {
					continue;
				}
				q.push({ nn, front.money });
				v[nn][front.money] = true;
			}
			else if (room[nn].first.first == 'L') {
				int n_money = max(front.money, room[nn].first.second);
				if (v[nn][n_money] == true) {
					continue;
				}
				q.push({ nn, n_money });
				v[nn][n_money] = true;
			}
			else if (front.money >= room[nn].first.second) {
				int n_money = front.money - room[nn].first.second;
				if (v[nn][n_money] == true) {
					continue;
				}
				q.push({ nn, n_money });
				v[nn][n_money] = true;
			}
		}
	}

	return is_goal;
}

int main() {
	while (1) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		string ans = "Yes";
		if (!solve(n)) {
			ans = "No";
		}

		cout << ans << "\n";
	}

	return 0;
}