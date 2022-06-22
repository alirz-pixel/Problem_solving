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
			vector<bool> visit_num(10); // 1 ~ 9;

			for (int y = 0; y < 9; y++) {
				if (visit_num[board[y][x]]) {
					is_sudoku = false;
					break;
				}

				visit_num[board[y][x]] = true;
			}

			if (!is_sudoku) {
				break;
			}
		}
			 
		// 가로 검사
		if (is_sudoku) {
			for (int y = 0; y < 9; y++) {
				vector<bool> visit_num(10); // 1 ~ 9;

				for (int x = 0; x < 9; x++) {
					if (visit_num[board[y][x]]) {
						is_sudoku = false;
						break;
					}

					visit_num[board[y][x]] = true;
				}

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