#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define MAX 7

using namespace std;

struct Compare {
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

int main() {
	cin.tie(0);     
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		vector<int> arr(MAX);
		for (auto& i : arr) {
			cin >> i;
		}

		set<int, Compare> sum;
		for (int i = 0; i < MAX; i++) {
			for (int j = i + 1; j < MAX; j++) {
				for (int k = j + 1; k < MAX; k++) {
					sum.insert(arr[i] + arr[j] + arr[k]);
				}
			}
		}

		auto ans = next(sum.begin(), 4);
		
		cout << "#" << tc << " " << *ans << "\n";
	}

	return 0;
}