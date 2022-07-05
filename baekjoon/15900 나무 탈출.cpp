#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int ans = 0;

void dfs(int root, int depth) {
	visited[root] = true;
	bool is_child_node = true;

	for (auto i : tree[root]) {
		if (visited[i]) {
			continue;
		}

		is_child_node = false;
		dfs(i, depth + 1);
	}

	if (is_child_node) {
		ans += depth;
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

	dfs(0, 0);
	cout << ((ans % 2 == 1) ? "Yes" : "No");

	return 0;
}
