#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;

vector<vi> graph;
vector<bool> visited;
vector<int> connect;

bool dfs(int x) {
	for (int i = 0; i < graph[x].size(); i++) {
		int t = graph[x][i];

		if (visited[t]) {
			continue;
		}
		visited[t] = true;

		if (connect[t] == -1 || dfs(connect[t])) {
			connect[t] = x;
			return true;
		}
	}

	return false;
}

int main() {
	int n;
	cin >> n;

	graph.assign(n, vector<int>());
	connect.assign(n, -1);

	queue<int> z_zero_q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x != 0) {
			for (int j = 0; j < x; j++) {
				int target_vtx;
				cin >> target_vtx;
				target_vtx--;

				if (target_vtx > i) {
					graph[target_vtx].push_back(i);
				}
			}
		}
		else {
			z_zero_q.push(i);
		}
	}

	int ans = n;
	while (!z_zero_q.empty()) {
		visited.assign(n, false);
		
		int front = z_zero_q.front();
		if (!dfs(front)) {
			ans = front;
			break;
		}

		z_zero_q.pop();
	}

	cout << ans;

	return 0;
}
