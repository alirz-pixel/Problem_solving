#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) {
		cin >> i;	
	}

	vector<int> _LIS;
	for(auto i : A) {
		int left = 0;
		int right = _LIS.size();

		while (left < right) {
			int mid = (left + right) / 2;

			if (_LIS[mid] <= i) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

		if (right == _LIS.size()) {
			_LIS.push_back(i);
		}

		else if (_LIS[right] < i) {
			_LIS[right] = i;
		}
	}

	cout << _LIS.size();

	return 0;
}