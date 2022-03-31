#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		string str;
		cin >> str;

		vector<int> arr(26);
		for (auto i : str) {
			arr[i - 'a']++;
		}

		// 짝수개 구하기
		int even = 0, odd = 0;
		for (auto i : arr) {
			if (i % 2) odd++;
			even += (i / 2);
		}

		odd += (even % k) * 2;

		int ans = even / k * 2;
		if (odd >= k) {
			ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}