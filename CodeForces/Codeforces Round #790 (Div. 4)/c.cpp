#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> str(n);
		for (auto& i : str) {
			cin >> i;
		}

		int minV = 987654321;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int total = 0;
				for (int k = 0; k < m; k++) {
					total += abs(str[i][k] - str[j][k]);
				}

				minV = min(minV, total);
			}
		}

		cout << minV << "\n";
	}

	

	return 0;
}
