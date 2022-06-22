#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		int b_money = (w <= r ? q : q + s * (w - r));
		int ans = min(p * w, b_money);
		
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}