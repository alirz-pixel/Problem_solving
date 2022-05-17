#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr(n);
		for (auto& i : arr) {
			cin >> i;
		}

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] >= arr[j]) {
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
