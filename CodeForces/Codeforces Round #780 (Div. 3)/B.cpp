#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using lld = long long;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<lld> arr(n);
		priority_queue<lld> pq;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];

			pq.push(arr[i]);
		}

		string ans = "YES";
		if (pq.size() == 1 && pq.top() >= 2) {
			ans = "NO";
		}
		else if (pq.size() != 1) {
			lld max = pq.top();
			pq.pop();

			if (max - pq.top() >= 2) {
				ans = "NO";
			}
		}
		cout << ans << "\n";
	}

	return 0;
}