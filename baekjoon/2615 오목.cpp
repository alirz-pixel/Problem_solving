/* 2022-03-23  05:35
백준 2615번 오목  ||  실버 2
https://www.acmicpc.net/problem/2615

분야 : [ 구현, 브루트포스 ]


==============================
단순히 위에서부터 아래로, 왼쪽에서부터 오른쪽으로 차례대로 탐색하면 쉽게 풀릴 줄 알았으나,

오른쪽 대각선 위로 향하는 방향에 대해서 문제가 발생하여
2번이나 틀리게 되었다.

그리고 not_win을 따로 생각해야 된다는 점이 좀 골치아팠다.
==============================


시작시간 : 04:55
종료시간 : 05:35       [시도횟수 : 3회  |  걸린시간 : 40분]
*/

#include <iostream>
#define MAX 19
#define MAX_DIR 3

using namespace std;

int board[MAX][MAX];
int dy[MAX_DIR + 1] = { 1, 0, 1, -1 };
int dx[MAX_DIR + 1] = { 0, 1, 1, 1 };

bool not_win[MAX][MAX][MAX_DIR + 1] = { 0, };

int DFS(int depth, int ny, int nx, int dir, int color) {

	if (ny < 0 || ny >= MAX || nx < 0 || nx >= MAX || board[ny][nx] != color) {
		return depth;
	}

	if (board[ny][nx] == color) {
		int cnt = DFS(depth + 1, ny + dy[dir], nx + dx[dir], dir, color);
		if (cnt == 5) {
			return cnt;
		}
		else {
			not_win[ny][nx][dir] = true;
			return cnt;
		}
	}

	return depth;
}

int main() {
	for (auto& y : board) {
		for (auto& x : y) {
			cin >> x;
		}
	}


	// solve(); 
	int win = 0;
	int win_y, win_x;
	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			for (int dir = 0; dir < MAX_DIR; dir++) {
				int color = board[y][x];

				if (not_win[y][x][dir] == true) {
					continue;
				}

				if (color == 0) {
					break;
				}

				if (DFS(1, y + dy[dir], x + dx[dir], dir, color) == 5) {
					win = color;
					win_y = y + 1;
					win_x = x + 1;
					break;
				}
				else {
					not_win[y][x][dir] = true;
				}
			}

			if (win) {
				break;
			}
		}

		if (win) {
			break;
		}
	}

	if (!win) {
		for (int y = MAX - 1; y >= 0; y--) {
			for (int x = MAX - 1; x >= 0; x--) {
				int color = board[y][x];

				if (not_win[y][x][3] == true || color == 0) {
					continue;
				}

				if (DFS(1, y + dy[3], x + dx[3], 3, color) == 5) {
					win = color;
					win_y = y + 1;
					win_x = x + 1;
				}
				else {
					not_win[y][x][3] = true;
				}
			}

			if (win) {
				break;
			}
		}
	}


	cout << win << "\n";
	if (win) {
		cout << win_y << " " << win_x;
	}
	return 0;
}