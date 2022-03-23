#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int t = 0;

	while (++t) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		cin.ignore();
		cin.clear();

		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			getline(cin, arr[i]);
		}


		vector<bool> check(n + 1);

		int stu_num;
		char alpha;
		for (int i = 0; i < (2 * n) - 1; i++) {
			cin >> stu_num;

			cin.ignore();
			cin.clear();
			cin >> alpha;

			check[stu_num] = !check[stu_num];
		}


		for (int i = 1; i <= n; i++) {
			if (check[i] == true) {
				cout << t << " " << arr[i - 1] << "\n";
				break;
			}
		}
	}

	return 0;
}