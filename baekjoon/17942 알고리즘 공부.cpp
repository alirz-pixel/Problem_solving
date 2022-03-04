#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct EDGE {
	int end;
	int cost;

	EDGE() {};
	EDGE(int _end, int _cost) { end = _end; cost = _cost; };
};

int N, M, K;
int A, B, D;
vector<int> study;
vector<vector<EDGE>> graph;

// 그래프 확인
bool is_true(int study_time_limit) {
	vector<int> copy(N);
	vector<bool> v(N);

	queue<int> q;
	int learned_cnt = 0;

	// 그냥 익힐 수 있는지 확인
	for (int i = 0; i < study.size(); i++) {
		copy[i] = study[i];

		if (study[i] <= study_time_limit) {
			q.push(i);
			learned_cnt++;
			v[i] = true; 

			if (learned_cnt >= M) {
				return true;
			}
		}
	}

	// 연관성 확인
	while (!q.empty()) {
		int _front = q.front();
		q.pop();

		for (auto i : graph[_front]) {
			if (v[i.end]) {
				continue;
			}

 			copy[i.end] -= i.cost;

			if (copy[i.end] <= study_time_limit) {
				learned_cnt++;
				v[i.end] = true;
				q.push(i.end);

				if (learned_cnt >= M) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);


	int left = INT_MAX, right = INT_MIN;
	cin >> N >> M;

	study = vector<int>(N);
	for (auto& i : study) {
		cin >> i;

		left = min(left, i);
		right = max(right, i);
	}

	cin >> K;
	graph = vector<vector<EDGE>>(N);
	for (int i = 0; i < K; i++) {
		cin >> A >> B >> D;
		A--; B--;

		graph[A].push_back(EDGE(B, D));
	}
	

	// solve();
	int mid, ret = INT_MAX;
	while (left <= right) {
		mid = (left + right) / 2;

		if (is_true(mid)) {
			right = mid - 1;

			ret = min(ret, mid);
		}
		else {
			left = mid + 1;
		}
	}

	cout << ret << "\n";
	return 0;
}
