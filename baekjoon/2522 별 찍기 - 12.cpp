#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < (2 * n) - 1; i++) {
		for (int j = 0; j < n; j++) {
			// 증가
			if (i < n) {
				if (j >= (n - i)-1) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}

			// 감소
			else {
				if (j >= (i + 1) - n) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
		}

		cout << "\n";
	}

	return 0;
}