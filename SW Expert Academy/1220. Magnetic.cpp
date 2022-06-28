#include <iostream>
#include <vector>
#define TESTCASE 10
#define BOARDMAX 100

using namespace std;

int calc_deadlock(vector<vector<int>>& board) {
	int cnt = 0;

	// x -> y
	for (int x = 0; x < BOARDMAX; x++) {
		int y_top = 0;

		while (y_top < BOARDMAX) { 
			while (y_top < BOARDMAX && board[y_top][x] != 1) {
				y_top++; // N 찾기
			}

			while (y_top < BOARDMAX && board[y_top][x] != 2) {
				y_top++; // N 과 짝이 맞는 S 찾기
			}

			if (y_top == BOARDMAX) {
				break;
			}

			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin.tie(0);     cout.tie(0);
	ios::sync_with_stdio(false);

	for (int tc = 1; tc <= TESTCASE; tc++) {
		int dummy;
		cin >> dummy;

		vector<vector<int>> board(BOARDMAX, vector<int>(BOARDMAX));
		for (auto& y : board) {
			for (auto& x : y) {
				cin >> x;
			}
		}

		int ans = calc_deadlock(board);

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}