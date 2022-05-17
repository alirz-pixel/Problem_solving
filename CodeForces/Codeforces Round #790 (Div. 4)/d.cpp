#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
long long n, m;

long long cnt(long long y, long long x) {
	long long ret = 0;
	// 대 오 위
	long long nx = x;
	long long ny = y;
	while (ny >= 0 && nx < m) {
		ret += board[ny][nx];
		ny += -1;
		nx += 1;
	}

	// 대 오 아래
	nx = x;
	ny = y;
	while (ny < n && nx < m) {
		ret += board[ny][nx];
		ny += 1;
		nx += 1;
	}
	ret -= board[y][x];

	// 대 왼 위
	nx = x;
	ny = y;
	while (ny >= 0 && nx >= 0) {
		ret += board[ny][nx];
		ny += -1;
		nx += -1;
	}
	ret -= board[y][x];

	// 대 왼 아
	nx = x;
	ny = y;
	while (ny < n && nx >= 0) {
		ret += board[ny][nx];
		ny += 1;
		nx += -1;
	}
	ret -= board[y][x];

	return ret;
}

int main() {
	long long t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		board.assign(n, vector<int>(m));
		for (auto& y : board) {
			for (auto& x : y) {
				cin >> x;
			}
		}

		long long maxV = 0;
		for (long long y = 0; y < n; y++) {
			for (long long x = 0; x < m; x++) {
				maxV = max(maxV, cnt(y, x));
			}
		}

		cout << maxV << "\n";
	}

	return 0;
}
