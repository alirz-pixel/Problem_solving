// 걸린시간 : 32분


#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct COORD {
	int y;
	int x;

	COORD() {};
	COORD(int _y, int _x) { y = _y; x = _x; };
};

int main() {
    // 문자열 길이 입력받기
	int len;
	cin >> len;

    // 문자열 입력받기
	string S;
	cin >> S;

	//남쪽에서 시작 - 'F'를 입력받을 경우, dir 값이 가리키는 곳으로 이동하기 위함
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, -1, 0, 1 };
	int dir = 0;

    
	queue<COORD> move_q; // 입력받은 문자열 S에 대해 탐색이 끝난 후, 지나온 경로를 확인하기 위함
	COORD cur(0, 0); // 현재 위치
	COORD min_s(0, 0), max_s(0, 0); // 보드의 사이즈를 계산하기 위한 변수
	
	move_q.push(COORD(cur.y, cur.x));
	for (auto i : S) {
		if (i == 'L') {
			dir = ((dir - 1) + 4) % 4; // 왼쪽 바라보기 - dir이 -1 이 될 경우, 3이 되도록 함.
		}
		else if (i == 'R') {
			dir = (dir + 1) % 4; // 오른쪽 바라보기 - dir이 5가 될 경우, 0이 되도록 함.
		}
		else { // 앞으로 이동
			cur.y += dy[dir];
			cur.x += dx[dir];

			move_q.push(COORD(cur.y, cur.x)); // 지나온 경로 push

            // 현재 위치에 대해 min, max 계산하기
			min_s.y = min(min_s.y, cur.y);
			min_s.x = min(min_s.x, cur.x);

			max_s.y = max(max_s.y, cur.y);
			max_s.x = max(max_s.x, cur.x);
		}
	}

    // 보드 사이즈 계산
	int y_size = (max_s.y + 1) - min_s.y;
	int x_size = (max_s.x + 1 ) - min_s.x;

	vector<vector<char>> board(y_size, vector<char>(x_size, '#'));
	while (!move_q.empty()) {
        // 여태까지 지나온 경로를 '.'으로 만듬
		board[move_q.front().y - min_s.y][move_q.front().x - min_s.x] = '.';
		move_q.pop();
	}

    // 보드가 뒤집혀 있으므로 y는 y_size - 1부터 시작
	for (int y = y_size - 1; y >= 0; y--) {
		for (auto x : board[y]) {
			cout << x;
		}
		cout << "\n";
	}

	return 0;
}