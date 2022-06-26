#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#define PASSWDLENGTH 8

using namespace std;

int main() {
	vector<int> arr(PASSWDLENGTH);
	
	for (int tc = 1; tc <= 10; tc++) {
		int dummy_tc;
		cin >> dummy_tc;


		int minV = INT_MAX;
		for (auto &i : arr) {
			cin >> i;

			minV = min(minV, i);
		}
		
		int minus_value = (minV - 1) / 15 * 15;
		for (auto& i : arr) {
			i -= minus_value;
		}

		int head_idx = 0;
		int cycle = 1;
		while (arr[head_idx] > 0) {
			arr[head_idx] -= cycle;
			cycle = cycle % 5 + 1;

			if (arr[head_idx] <= 0) {
				arr[head_idx] = 0;
				break;
			}
			head_idx = (head_idx + 1) % PASSWDLENGTH;
		}

		cout << "#" << tc << " ";

		for (int i = 0; i < PASSWDLENGTH; i++) {
			head_idx = (head_idx + 1) % PASSWDLENGTH;
			cout << arr[head_idx] << " ";
		}
		cout << "\n";
	}
}