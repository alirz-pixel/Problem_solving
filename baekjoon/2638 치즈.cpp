/* 2022-03:17  11:13
백준 2638번 치즈 || 골드 4
https://www.acmicpc.net/problem/2638

분야 : [ DFS, BFS ]

================================
[ 오답 사유 ]
 - DFS/BFS를 이용해 '외부 공기'를 판단하는 방식을 생각하지 못함.
 - 메모리 초과를 해결하지 못하고 코드를 다시 짬.
 - 어렵게 짜려고 했다는 점.
  1. vistied를 관리하는 배열을 추가로 선언하려고 하지 않음.
  2. 녹은 치즈 판단을 queue에 넣어서 관리하려고 함.
================================

시작시간 : **:**
종료시간 : **:**   ||  [ 시도횟수 : 5회  |  걸린시간 : **분 ]
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> board;

int N, M;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void print_board() {
	for (auto i : board) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void find_out() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	vector<vector<bool>> v(N, vector<bool>(M));
	v[0][0] = true;

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = curr.first + dx[dir];
			int ny = curr.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N || v[ny][nx] || board[ny][nx] == 1) {
				continue;
			}

			q.push({ nx, ny });
			v[ny][nx] = true;
			board[ny][nx] = 2;
		}
	}
}

int melt_cheese() {
	int ny, nx, cnt, ret, ans = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) { 
			if (board[y][x] != 1) {
				continue;
			}

			cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				ny = y + dy[dir];
				nx = x + dx[dir];


				if (ny < 0 || nx >= M || nx < 0 || ny >= N) {
					continue;
				}

				if (board[ny][nx] == 2) {
					cnt++;
				}
			}

			if (cnt >= 2) {
				ans++;
				board[y][x] = 0;
			}
		}
	}

	return ans;
}

void BFS() {

	int ans = 0;
	int melt_cnt;
	while (1) {
		find_out();
		melt_cnt = melt_cheese();

		if (melt_cnt == 0) {
			break;
		}

		ans++;
	}

	cout << ans;
}

int main() {
	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (auto& i : board) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	BFS();

	return 0;
}