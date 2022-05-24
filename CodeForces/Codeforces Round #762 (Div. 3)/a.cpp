#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		if (str.length() % 2 == 1) {
			cout << "NO\n";
			continue;
		}
		
		int div2 = str.length() / 2;
		if (str.substr(0, div2) == str.substr(div2)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
