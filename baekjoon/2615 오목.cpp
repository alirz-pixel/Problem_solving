/* 2022-03-23  05:35
백준 2615번 오목  ||  실버 2
https://www.acmicpc.net/problem/2615

분야 : [ 구현, 브루트포스 ]


==============================
-재시도- 

방문 처리 실수로 1번 틀렸으나,
전체적으로 코드를 깔끔하게 작성하도록 노력하면서 함
=============================함


시작시간 : **:**
종료시간 : **:**       [시도횟수 : 2회  |  걸린시간 : ??분]
*/


#include <iostream>
#define MAX 19

using namespace std;

int board[MAX][MAX];

int cols[MAX][10], rows[MAX][10];
int square[3][3][10];

int dy[] = { 0, 1, 1, 1};
int dx[] = { 1, 0, 1, -1};

bool v[MAX][MAX][4] = { 0, };

bool find_omok(int y, int x, int color, int dir, int depth) {
	if (v[y][x][dir]) {
		return false;
	}

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (board[nx][ny] != color) {
		return depth == 5 ? true : false;
	}

	return v[y][x][dir] = find_omok(ny, nx, color, dir, depth + 1);
}

pair<pair<int, int>, int> solve() {
	bool is_true = false;

	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			for (int dir = 0; dir < 4; dir++) {
				if (board[y][x] != 0) {
					if (find_omok(y, x, board[y][x], dir, 0)) {
						if (dir != 4) {
							return {{ y + 1, x + 1 }, board[y][x] };
						}
						else {
							return {{ y - 3, x - 3 }, board[y][x] };
						}
					}
				}
			}
		}
	}

	return {{ 0, 0 }, 0 };
}

int main() {;
	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			cin >> board[y][x];	

			if (auto i = board[y][x]) {
				rows[y][i] = true; 
				cols[x][i] = true;

				square[y / 3][x / 3][i] = true;
			}
		}
	} 

	pair<pair<int, int>, int> result = solve();
	if (result.second == 0) {
		cout << "0";
	}
	else {
		cout << result.second << "\n";
		cout << result.first.first << " " << result.first.second;
	}

	return 0;
}
