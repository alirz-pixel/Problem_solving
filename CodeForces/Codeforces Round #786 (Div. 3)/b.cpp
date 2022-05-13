#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		cout << ((str[0] - 'a') * 25) + (str[1] - 'a') + ((str[0] < str[1]) ? -1 : 0) + 1 << "\n";
	}
}
