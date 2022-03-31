#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int maxV = -1;
		int minV = INT_MAX;
		vector<int> arr(n);
		for (auto& i : arr) {
			cin >> i;
			maxV = max(maxV, i);
			minV = min(minV, i);
		}


		cout << maxV - minV << "\n";
	}

	return 0;
}