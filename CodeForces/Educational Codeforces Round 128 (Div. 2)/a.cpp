#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int l[2];
		int r[2];

		cin >> l[0] >> r[0];
		cin >> l[1] >> r[1];

		if (l[0] > r[1] || r[0] < l[1]) {
			cout << l[0] + l[1] << "\n";
		}
		else {
			// 중복되는 친구 중 작은 친구
			cout << max(l[0], l[1]) << "\n";
		}
	}

	return 0;
}
