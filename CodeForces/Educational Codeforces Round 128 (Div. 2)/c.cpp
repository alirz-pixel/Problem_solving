#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		int zeros = 0, ones = 0;
		for (auto i : str) {
			i == '0' ? zeros++ : ones++;
		}

		int zero = 0, one = ones;
		int j = 0, ans = str.size();
		for (int i = 0; i < str.size(); i++) {
			while (j < str.size() && zero < one) {
				str[j] == '0' ? zero++ : one--;
				j++;
			}

			ans = min(ans, max(zero, one));
			str[i] == '0' ? zero-- : one++;
		}

		cout << ans << "\n";
	}

	return 0;
}
