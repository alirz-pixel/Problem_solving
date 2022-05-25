#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> graph;
int n, m;

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		graph.assign(n, "");

		vector<int> row(n);
		vector<int> col(m);

		for (int y = 0; y < n; y++) {
			cin >> graph[y];

			for (int x = 0; x < m; x++) {
				if (graph[y][x] == 'R') {
					row[y]++;
					col[x]++;
				}
			}
		}

		int row_idx = 0, col_idx = 0;
		while (row[row_idx] == 0 || col[col_idx] == 0) {
			if (row[row_idx] == 0) {
				row_idx++;
			}
			if (col[col_idx] == 0) {
				col_idx++;
			}
		}

		// cout << row_idx << " " << col_idx << "\n";
		cout << (graph[row_idx][col_idx] == 'E' ? "NO" : "YES") << "\n";
	}

	return 0;
}
