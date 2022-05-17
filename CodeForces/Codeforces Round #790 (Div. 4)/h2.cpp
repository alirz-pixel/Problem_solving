
#include <iostream>
#include <vector>

using namespace std;

vector<int> seg;

void update(int nodeIdx, int left, int right, int updateIdx) {
	if (updateIdx < left || right < updateIdx) {
		return;
	}

	if (left == updateIdx && updateIdx == right) {
		seg[nodeIdx]++;
		return;
	}

	int mid = (left + right) / 2;
	update(nodeIdx * 2, left, mid, updateIdx);
	update(nodeIdx * 2 + 1, mid + 1, right, updateIdx);
	seg[nodeIdx] = seg[nodeIdx * 2] + seg[nodeIdx * 2 + 1];
}

int query(int nodeIdx, int left, int right, int start, int end) {
	if (right < start || end < left) {
		return 0;
	}

	if (start <= left && right <= end) {
		return seg[nodeIdx];
	}


	int mid = (left + right) / 2;
	return query(nodeIdx * 2, left, mid, start, end) + query(nodeIdx * 2 + 1, mid + 1, right, start, end);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		seg.assign(4 * n, 0);

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			cnt += query(1, 1, n, a, n);
			update(1, 1, n, a);
		}

		cout << cnt << "\n";
	}

	return 0;
}

