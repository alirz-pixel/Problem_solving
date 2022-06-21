#include <iostream>
#define NUM 10

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int odd_tot = 0;

		for (int i = 0; i < NUM; i++) {
			int cur;
			cin >> cur;

			if (cur % 2 == 1) {
				odd_tot += cur;
			}
		}

		cout << "#" << tc << " " << odd_tot << "\n";
	}

	return 0;
}