#include <iostream>
#define MAX 9

using namespace std;

int board[MAX][MAX];
// 중복 배열을 어떻게 관리할 것인가
bool cols[MAX][10], rows[MAX][10];
bool squares[3][3][10];

void print_board() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool backtracking(int y, int x) {
	if (x == 9) {
		x = 0;
		y++;

		if (y == 9) {
			if (board[8][8] != 0) {
				print_board();
				exit(0);
			}
			else {
				return false;
			}
		}
	}

	// bool is_fill = true; // 현재 칸을 채워야 하는 가?
	bool is_fill_true = false; // 현재 칸을 채워야 하는데 채울 수 있는가?


	if (board[y][x] == 0) {
		for (int curr = 1; curr <= MAX; curr++) {
			if (!cols[y][curr] && !rows[x][curr] && !squares[y / 3][x / 3][curr]) {
				cols[y][curr] = true;
				rows[x][curr] = true;
				squares[y / 3][x / 3][curr] = true;

				board[y][x] = curr;

				is_fill_true = true;
				if (backtracking(y, x + 1)) {
					return true;
				}
				is_fill_true = false;

				board[y][x] = 0;

				cols[y][curr] = false;
				rows[x][curr] = false;
				squares[y / 3][x / 3][curr] = false;
			}
		}
	}
	else {
		if (backtracking(y, x + 1)) {
			return true;
		}
	}

	return false;
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0) {
				cols[i][board[i][j]] = true;
				rows[j][board[i][j]] = true;
				squares[i / 3][j / 3][board[i][j]] = true;
			}
		}
	}

	backtracking(0, 0);

	return 0;
}