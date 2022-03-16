/* 2022-02-23  19:55
백준 14503번 로봇 청소기 || 골드 5
https://www.acmicpc.net/problem/14503

분야 : [ 구현, 시뮬레이션 ]

================================
문제를 제대로 읽지않아 뒤로 1칸 후진해야 할 것을
2칸 후진해야 된다 생각하여 꽤나 오래걸리게 되었다..
================================

시작시간 : 19:20
종료시간 : 19:56   ||  [ 시도횟수 : 1회  |  걸린시간 : 36분 ]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

struct Robot {
	int y;
	int x;
	int d;

	Robot() {};
	Robot(int _x, int _y, int _d) { x = _x; y = _y; d = _d; };
};
Robot robot;

int N, M;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void print_board() {
	for (auto i : graph) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve() {
	vector<vector<bool>> v(N, vector<bool>(M));
	int cnt = 0;
	while (1) {
		// 현재 위치 청소하기
		if (v[robot.y][robot.x] == false && graph[robot.y][robot.x] == 0) {
			// graph[robot.y][robot.x] = 2;
			v[robot.y][robot.x] = true;
			cnt++;
		}

		bool is_move = false;

		int dir = robot.d;
		int ny, nx;
		for (int i = 0; i < 4; i++) {
			// 왼쪽을 보기
			dir = ((dir - 1) + 4) % 4;

			// 다음으로 가려는 곳
			ny = robot.y + dy[dir];
			nx = robot.x + dx[dir];

			// 방문처리 및 벽
			if (graph[ny][nx] == 1 || v[ny][nx]) {
				continue;
			}

			// 빈 곳으로 이동
			if (graph[ny][nx] == 0) {
				// graph[ny][nx] = 2;
				robot.y = ny;
				robot.x = nx;
				robot.d = dir;

				is_move = true;
				break;
			}
		}

		// 네 방향 모두 벽이거나 청소가 된 상태라면
		// ny, nx를 현재 좌표로 지정;
		ny = robot.y;
		nx = robot.x;

		// 뒤로 이동
		if (!is_move) {
			// 뒤에 벽이 있는가?
			if (graph[ny - dy[dir]][nx - dx[dir]] == 1) {
				break;
			}

			robot.y = ny - dy[dir];
			robot.x = nx - dx[dir];
			robot.d = dir;
		}

		print_board();
	}

	cout << cnt;
}

int main() {
	cin >> N >> M;

	cin >> robot.y >> robot.x >> robot.d;

	graph = vector<vector<int>>(N, vector<int>(M));
	for (auto& i : graph) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	solve();

	return 0;
}