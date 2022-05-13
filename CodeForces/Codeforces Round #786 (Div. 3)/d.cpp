#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> arr(n);
		vector<int> sorted_arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sorted_arr[i] = arr[i];
		}

		sort(sorted_arr.begin(), sorted_arr.end());		

		int idx = 0;
		bool is_true = true;

		if (n % 2 == 1) {
			if (sorted_arr[0] != arr[0]) {
				is_true = false;
			}

			idx++;
		}

		if (is_true) {
			while (idx < n) {
				// 2개씩 짤라서 한번 봅시다. ㅇㅇ
				if (min(arr[idx], arr[idx + 1]) != min(sorted_arr[idx], sorted_arr[idx + 1]) || max(arr[idx], arr[idx + 1]) != max(sorted_arr[idx], sorted_arr[idx + 1])) {
					is_true = false;
					break;
				}

				idx += 2;
			}
		}

		if (is_true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
