#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int fa = b - (c - b);
		int fc = b + (b - a);
		int fb = (a + c) / 2;

		if (fa > 0 && fa % a == 0) {
			cout << "YES\n";
		}
		else if (fb % b == 0 && (a + c) % 2 == 0) {
			cout << "YES\n";
		}
		else if (fc > 0 && fc % c == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}