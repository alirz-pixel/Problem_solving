#include <iostream>
#include <vector>

using namespace std;

bool is_sudoku_block(vector<vector<int>>& board) {
	for (int y_block = 0; y_block < 3; y_block++) {
		for (int x_block = 0; x_block < 3; x_block++) {
			vector<int> visit_num(10);

			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (visit_num[board[y_block * 3 + y][x_block * 3 + x]]) {
						return false;
					}

					visit_num[board[y_block * 3 + y][x_block * 3 + x]] = true;
				}
			}
		}
	}

	return true;
}

bool is_sudoku_ho_and_ver(vector<vector<int>>& board, bool horizontal, int idx) {
	vector<bool> visit_num(10); // 1 ~ 9;
	for (int repeat = 0; repeat < 9; repeat++) {
		if (horizontal) { // 가로 검증
			int cur = board[idx][repeat];

			if (visit_num[cur]) {
				return false;
			}
			visit_num[cur] = true;
		}
		else { // 세로 검증
			int cur = board[repeat][idx];

			if (visit_num[cur]) {
				return false;
			}
			visit_num[cur] = true;
		}
	}

	return true;
}

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		vector<vector<int>> board(9, vector<int>(9));
		for (auto& y : board) {
			for (auto& x : y) {
				cin >> x;
			}
		}

		bool is_sudoku = true;

		// 세로 검사
		for (int x = 0; x < 9; x++) {
			is_sudoku = is_sudoku_ho_and_ver(board, false, x);

			if (!is_sudoku) {
				break;
			}
		}

		// 가로 검사
		if (is_sudoku) {
			for (int y = 0; y < 9; y++) {
				is_sudoku = is_sudoku_ho_and_ver(board, true, y);

				if (!is_sudoku) {
					break;
				}
			}
		}

		// block 검사
		if (is_sudoku) {
			is_sudoku = is_sudoku_block(board);
		}

		cout << "#" << tc << " " << is_sudoku << "\n";
	}

	return 0;
}