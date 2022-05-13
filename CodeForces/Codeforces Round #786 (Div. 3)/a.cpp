#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		if (y % x != 0) {
			cout << "0 0\n";
			continue;
		}
		
		cout << 1 << " " << y / x << "\n";
	}

	return 0;
}
