#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int q;
	cin >> q;

	while (q--) {
		string s, t;
		cin >> s >> t;

		int a_cnt = 0;
		for (auto i : t) {
			if (i == 'a') {
				a_cnt++;
			}
		}

		if (a_cnt != 0 && t.length() > 1) {
			cout << -1 << "\n";
			continue;
		}

		if (t == "a") {
			cout << 1 << "\n";
			continue;
		}

		long long cnt = 1;
		cout << (cnt << s.length()) << "\n";

	}

	return 0;
}
