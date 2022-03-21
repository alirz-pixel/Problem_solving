// 걸린시간 : 15분

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);
	for (auto& i : A) {
		cin >> i.first;
	}

	vector<pair<int, int>> A_reverse = A;
	reverse(A_reverse.begin(), A_reverse.end());

	vector<int> _LIS_reverse;
	for (auto& i : A_reverse) {
		int index = lower_bound(_LIS_reverse.begin(), _LIS_reverse.end(), i.first) - _LIS_reverse.begin();

		if (_LIS_reverse.size() == index) {
			_LIS_reverse.push_back( i.first );
		}

		else {
			_LIS_reverse[index] = i.first;
		}

		i.second = index + 1;
	}

	reverse(A_reverse.begin(), A_reverse.end());

	vector<int> _LIS;
	for (auto& i : A) {
		int index = lower_bound(_LIS.begin(), _LIS.end(), i.first) - _LIS.begin();

		if (_LIS.size() == index) {
			_LIS.push_back(i.first);
		}

		else {
			_LIS[index] = i.first;
		}

		i.second = index + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, A[i].second + A_reverse[i].second - 1);
	}

	cout << ans;

	return 0;
}