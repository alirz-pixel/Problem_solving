#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		int a = 0, b = 0;
		for (int i = 0; i < 3; i++) {
			a += str[i] - '0';
		}

		for (int i = 3; i < 6; i++) {
			b += str[i] - '0';
		}

		if (a == b) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
