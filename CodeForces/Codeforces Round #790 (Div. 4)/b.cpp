#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int total = 0;
		int minV = 987654321;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;

			total += temp;
			minV = min(minV, temp);
		}

		cout << total - minV * n << "\n";
	}

	return 0;
}
