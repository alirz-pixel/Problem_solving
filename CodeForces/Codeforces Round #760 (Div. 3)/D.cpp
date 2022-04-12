#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> arr(n);
		for (auto& i : arr) {
			cin >> i;
		}

		sort(arr.begin(), arr.end(), less<int>());

		int score = 0;
		int start = n - 1 - k, end = n - 1;
		for (int i = 0; i < k; i++) {
			// cout << "Start : " << arr[start] << "  end : " << arr[end] << "\n";
			score += arr[start--] / arr[end--];
		}

		for (int i = 0; i <= start; i++) {
			score += arr[i];
		}

		cout << score << "\n";
	}

	return 0;
}