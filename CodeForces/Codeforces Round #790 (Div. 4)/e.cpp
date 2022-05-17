#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<int> arr(n);
		for (auto& i : arr) {
			cin >> i;
		}

		sort(arr.rbegin(), arr.rend());

		for (int i = 1; i < n; i++) {
			arr[i] += arr[i - 1];
		}

		for (int i = 0; i < q; i++) {
			int temp;
			cin >> temp;

			int idx = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();

			if (idx >= arr.size()) {
				cout << -1 << "\n";
			}
			else {
				cout << idx + 1 << "\n";
			}

			cout << "\n";
		}
	}

	return 0;
}
