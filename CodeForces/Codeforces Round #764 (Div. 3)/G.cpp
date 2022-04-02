#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int u;
	int v;
	int w;
};

int _find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return parent[x];
	}

	return parent[x] = _find(parent, parent[x]);
}

void _union(vector<int>& parent, int a, int b) {
	int x = _find(parent, a);
	int y = _find(parent, b);

	if (x == y) {
		return;
	}

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<Edge> edge(m);
		for (auto& i : edge) {
			cin >> i.u >> i.v >> i.w;
			i.u--;
			i.v--;
		}

		
		int ans = 0;
		for (int mask = 1 << 30; mask > 0; mask = mask >> 1) {
			int cnt = 0;
			int temp = (ans | (mask - 1));

			vector<int> parent(n);
			for (int i = 0; i < parent.size(); i++) {
				parent[i] = i;
			}

			for (auto i : edge) {
				if (((temp & i.w) == i.w) && (_find(parent, i.u) != _find(parent, i.v))) {
					cnt++;
					_union(parent, i.u, i.v);
				}
			}

			if (cnt != n - 1) {
				ans += mask;
			}
		}

		cout << ans << "\n";
	}

	return 0;
} 