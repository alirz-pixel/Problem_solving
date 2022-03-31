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
		vector<bool> v(n + 1);
		for (auto& i : arr) {
			cin >> i;
		}

		string ans = "YES";
		for (auto i : arr) {

			while ((i > n || (i <= n && v[i])) && i != 0) {
				i /= 2;
			}

			if (i == 0 || v[i]) {
				ans = "NO";
				break;
			}

			v[i] = true;
		}

		cout << ans << "\n";
	}

	return 0;
}