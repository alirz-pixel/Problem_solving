/* 2022-03-01  23:05
백준 17144번 미세먼지 안녕! || 골드 4
https://www.acmicpc.net/problem/17144


분야 : [DP]


시작시간 : **:**
종료시간 : **:**     걸린시간 : 48분  |  시도횟수 : 1회
*/

#include <iostream>
#include <cstring>

using namespace std;

struct Airfilter {
	int y;
	int x;

	Airfilter() {};
	Airfilter(int _y, int _x) { y = _y; x = _x; };
};

int R, C, T;
int board[51][51];
Airfilter filter[2];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void print_board() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << board[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void cycle_up() {
	// left
	for (int y = filter[0].y - 1; y > 0; y--) {
		board[y][0] = board[y - 1][0];
	}

	// top
	for (int x = 0; x < C - 1; x++) {
		board[0][x] = board[0][x + 1];
	}

	// right
	for (int y = 0; y < filter[0].y; y++) {
		board[y][C - 1] = board[y + 1][C - 1];
	}

	// bottom
	for (int x = C - 1; x >= 1; x--) {
		board[filter[0].y][x] = board[filter[0].y][x - 1];
	}

	board[filter[0].y][1] = 0;
}

void cycle_down() {
	// left
	for (int y = filter[1].y + 1; y < R - 1; y++) {
		board[y][0] = board[y + 1][0];
	}

	// bottom
	for (int x = 0; x < C - 1; x++) {
		board[R - 1][x] = board[R - 1][x + 1];
	}

	// right
	for (int y = R - 1; y >= filter[1].y; y--) {
		board[y][C - 1] = board[y - 1][C - 1];
	}

	// top
	for (int x = C - 1; x > 1; x--) {
		board[filter[1].y][x] = board[filter[1].y][x - 1];
	}

	board[filter[1].y][1] = 0;
}

int solve() {
	int spread_dust;
	int board_temp[51][51] = { 0, };

	// T초동안
	while (T--) {	
		memcpy(board_temp, board, sizeof(board));

		// 확산하기
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (board[y][x] == -1) {
					continue;
				}

				spread_dust = board[y][x] / 5;

				for (int dir = 0; dir < 4; dir++) {
					int my = y + dy[dir];
					int mx = x + dx[dir];

					// 벽에 막혀 확산을 못함.
					if (my < 0 || mx < 0 || my >= R || mx >= C || board[my][mx] == -1) {
						continue;
					}

					board_temp[y][x] -= spread_dust;
					board_temp[my][mx] += spread_dust;
				}
			}
		}

		memcpy(board, board_temp, sizeof(board));

		cycle_up();
		cycle_down();
	}

	int ret = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (board[y][x] != -1) {
				ret += board[y][x];
			}
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> R >> C >> T;

	int filter_cnt = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> board[y][x];

			if (board[y][x] == -1) {
				filter[filter_cnt].y = y;
				filter[filter_cnt].x = x;

				filter_cnt++;
			}
		}
	}
	
	cout << solve();

	return 0;
}