#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	vector<int> snacks(n);
	for (auto& i : snacks) {
		cin >> i;
	}


	sort(snacks.begin(), snacks.end());

	int left = 0, right = snacks[snacks.size() - 1];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (mid == 0) {
			left++;
			continue;
		}

		int cnt = 0;
		for (auto i : snacks) {
			cnt += i / mid;
		}

		// 오른쪽 영역
		if (m <= cnt) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
