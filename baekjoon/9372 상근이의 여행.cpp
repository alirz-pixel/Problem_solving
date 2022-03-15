// 걸린시간 : 9분

#include <iostream>
#include <vector>

using namespace std;


int find(vector<int>& parent, int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = find(parent, parent[x]);
}

bool _union(vector<int>& parent, int x, int y){
	int a = find(parent, x);
	int b = find(parent, y);

	if (a == b) {
		return false;
	}
	
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}

	return true;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<int> parent(N);
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		int a, b;
		int cnt = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			a--; b--;

			if (_union(parent, a, b)) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}