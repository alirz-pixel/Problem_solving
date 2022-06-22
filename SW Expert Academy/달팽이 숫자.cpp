#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cout << "#" << tc << "\n";

		int n;
		cin >> n;

		vector<vector<int>> board(n, vector<int>(n));

		int num = 1;
		int cur_x = 0, cur_y = 0;
		for (int cnt = n - 1; cnt > 0; cnt -= 2) {
			for (int dir = 0; dir < 4; dir++) {
				for (int j = cnt; j > 0; j--) {
					board[cur_y][cur_x] = num++;

					cur_y += dy[dir];
					cur_x += dx[dir];
				}
			}

			cur_x += 1;
			cur_y += 1;
		}

		if (n % 2 == 1) {
			board[cur_y][cur_x] = num++;
		}

		for (auto i : board) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}