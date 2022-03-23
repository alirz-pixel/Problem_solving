// https://codeforces.com/problemset/problem/1644/A
// Difficulty : 800
// 걸린시간 : 4분

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		map<char, bool> key;
		
		string ans = "YES";
		for (auto i : s) {
			if ('a' <= i && i <= 'z') {
				key[i] = true;
			}

			else if (key[tolower(i)] == false) {
				ans = "NO";
				break;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}