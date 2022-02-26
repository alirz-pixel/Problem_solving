/*  2022-02-26  09:46
백준 2239번 스도쿠 || 골드4
https://www.acmicpc.net/problem/2239

분류 : [백트래킹]


=======================[풀이]==========================
..
=======================================================


*/



#include <iostream>
#include <vector>

#define MAXNUM 10
#define ROW 9
#define COL 9

using namespace std;

vector<string> board;
vector<vector<bool>> check_row;
vector<vector<bool>> check_col;
vector<vector<vector<bool>>> check_block;

void print_board() {
	for (auto i : board) {
		cout << i << "\n";
	}
}

bool DFS(int cnt) {
	if (cnt == 81) {
		print_board();
		exit(0);
	}


	int y = cnt / ROW;
	int x = cnt % COL;
	
	int num = int(board[y][x] - '0');

	if (num == 0) {
		for (int i = 1; i < MAXNUM; i++) {
			if (!check_row[y][i] && !check_col[x][i] && !check_block[y / 3][x / 3][i]) {
				board[y][x] = char(i + '0');

				check_row[y][i] = true;
				check_col[x][i] = true;
				check_block[y / 3][x / 3][i] = true;

				DFS(cnt + 1);

				board[y][x] = '0';

				check_row[y][i] = false;
				check_col[x][i] = false;
				check_block[y / 3][x / 3][i] = false;
			}
		}
	} 
	else {
		DFS(cnt + 1);
	}

	return false;
}

int main(void) {
	check_row = vector<vector<bool>>(ROW, vector<bool>(MAXNUM));
	check_col = vector<vector<bool>>(COL, vector<bool>(MAXNUM));
	check_block = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(MAXNUM)));
	board = vector<string>(ROW);

	for (auto& i : board) {
		cin >> i;
	}

	int num;
	for (int y = 0; y < ROW; y++) {
		for (int x = 0; x < COL; x++) {
			num = int(board[y][x] - '0');

			if (num != 0) {
				check_row[y][num] = true;
				check_col[x][num] = true;
				check_block[y / 3][x / 3][num] = true;
			}
		}
	}

	DFS(0);

	return 0;
}