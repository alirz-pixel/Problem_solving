#include <iostream>

using namespace std;

int dash_cnt(int num) {
	int dash_say_cnt = 0;

	while (num) {
		if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
			dash_say_cnt++;
		}
		num /= 10;
	}

	return dash_say_cnt;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int dash_say_cnt = dash_cnt(i);

		if (dash_say_cnt == 0) {
			cout << i;
		}
		else {
			while (dash_say_cnt--) {
				cout << "-";
			}
		}

		cout << " ";
	}

	return 0;
}