// https://codeforces.com/problemset/problem/1644/B
// difficulty : 800

#include <iostream>
#include <vector>

using namespace std;
vector<bool> v;

int cnt;

void backtrakcing(int depth, int end, vector<int>& fibo) {
	if (depth == end) {
		for (auto i : fibo) {
			cout << i << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}

	for (int i = 1; i <= end; i++) {
		if ((depth < 2 || (depth >= 2 && fibo[depth - 1] + fibo[depth - 2] != i)) && v[i] == false && cnt != end) {
			fibo[depth] = i;

			v[i] = true;
			backtrakcing(depth + 1, end, fibo);
			v[i] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> fibo(n);
		v = vector<bool>(n + 1);

		cnt = 0;
		backtrakcing(0, n, fibo);
	}
	return 0;
}