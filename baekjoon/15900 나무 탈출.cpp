#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int ans = 0;

void bfs() {
	queue<pair<int, int>> q;
	pair<int, int> front;

	visited[0] = true;
	q.push({ 0, 0 });

	while (!q.empty()) {
		front = q.front();
		q.pop();

		bool is_child_node = true;
		for (auto i : tree[front.first]) {
			if (visited[i]) {
				continue;
			}

			is_child_node = false;
			visited[i] = true;
			q.push({ i, front.second + 1 });
		}

		if (is_child_node) {
			ans += front.second;
		}
	}
}

int main() {
	int n;
	cin >> n;

	tree.assign(n, vector<int>());
	visited.assign(n, false);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bfs();
	cout << ((ans % 2) ? "Yes" : "No");

	return 0;
}
