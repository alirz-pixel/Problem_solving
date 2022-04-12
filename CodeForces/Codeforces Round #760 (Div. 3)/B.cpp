#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string ans;

		int n;
		cin >> n;

		cin >> ans;

		string temp;
		for (int i = 1; i < n - 2; i++) {
			cin >> temp;

			if (ans[ans.length() - 1] == temp[0]) {
				ans += temp[1];
			}
			else {
				ans += temp;
			}
		}

		if (ans.length() == n) {
			cout << ans << "\n";
		}
		else {
			temp = "";
			for (int i = ans.length(); i < n; i++) {
				temp += "a";
			}

			cout << ans << temp << "\n";
		}
	}
	return 0;
}