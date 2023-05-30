#include <iostream>
#include <vector>

using namespace std;
vector<bool> visit_hor;
vector<bool> visit_right_up;
vector<bool> visit_right_down;
vector<vector<int>> right_up;
vector<vector<int>> right_down;
int answer = 0;

void print_board(vector<vector<int>> arr) {
	for (int y = 0; y < arr.size(); y++) {
		for (int x = 0; x < arr[0].size(); x++) {
			printf("%2d ", arr[y][x]);
		}
		cout << "\n";
	}
	cout << "\n";

}

void fill_diagonal(int N) {
	int y = N - 1;
	int x = 0;
	bool is_up = true;
	int cnt = 0;
	while (true) {
		int cy = y;
		int cx = x;
		while (cx < N && cy < N) {
			right_up[cy][cx] = cnt;
			cy++;
			cx++;
		}
		cnt++;

		if (is_up) {
			y--;
		}
		else {
			x++;
		}

		if (x == N) {
			break;
		}
		else if (y == 0) {
			is_up = false;
		}
	}
	//print_board(right_up);

	y = 0;
	x = 0;
	bool is_right = true;
	cnt = 0;
	while (true) {
		int cy = y;
		int cx = x;
		while (cx >= 0 && cy < N) {
			right_down[cy][cx] = cnt;
			cy++;
			cx--;
		}
		cnt++;

		if (is_right) {
			x++;
		}
		else {
			y++;
		}

		if (y == N) {
			break;
		}
		else if (x == N - 1) {
			is_right = false;
		}
	}
	//print_board(right_down);
}

vector<int> queen_flags;
void find_n_queen(const int& N, int y) {
	/*for (int cy = 0; cy < N; cy++) {
		for (int x = 0; x < N; x++) {
			bool is_flag = false;
			if (cy < y && queen_flags[cy] == x) {
				cout << 2 << " ";
			}
			else if (cy < y || visit_hor[x] || visit_right_up[right_up[cy][x]] || visit_right_down[right_down[cy][x]]) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	

	if (y == N) {
		answer++;
		/*for (int i = 0; i < N; i++) {
			cout << queen_flags[i] << " ";
		}
		cout << "\n";*/

		return;
	}

	for (int x = 0; x < N; x++) {
		if (visit_hor[x] || visit_right_up[right_up[y][x]] || visit_right_down[right_down[y][x]]) {
			continue;
		}
		visit_hor[x] = true;
		visit_right_up[right_up[y][x]] = true;
		visit_right_down[right_down[y][x]] = true;

		queen_flags[y] = x;
		find_n_queen(N, y + 1);

		visit_hor[x] = false;
		visit_right_up[right_up[y][x]] = false;
		visit_right_down[right_down[y][x]] = false;
	}
}

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1;
		return 0;
	}
	if (N < 4) {
		cout << 0;
		return 0;
	}

	visit_hor.assign(N, false);
	visit_right_up.assign(2 * N - 1, false);
	visit_right_down.assign(2 * N - 1, false);
	right_up.assign(N, vector<int>(N));
	right_down.assign(N, vector<int>(N));
	queen_flags.assign(N, -1);

	fill_diagonal(N);
	find_n_queen(N, 0);

	cout << answer;

	return 0;
}