#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int> b;

	while (t--) {
		b.assign(7, 0);

		for (auto& input : b) {
			cin >> input;
		}

		sort(b.begin(), b.end(), less<int>());

		vector<int> a(3);
		a[0] = b[0];
		a[1] = b[1];

		for (int i = 2; i < 7; i++) {
			if (a[0] + a[1] != b[i] || b[i] == b[i - 1]) {
				a[2] = b[i];
				break;
			}
		}

		for (auto i : a) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}