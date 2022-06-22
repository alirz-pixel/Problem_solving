#include <algorithm>
#include <iostream>

using namespace std;

string num, result;
int change_cnt;

void DFS(int n, int depth) {
	if (depth == change_cnt) {
		result = (result == "") ? num : max(result, num);
		return;
	}

	for (int i = n; i < num.size() - 1; i++) {
		for (int j = i + 1; j < num.size(); j++) {
			swap(num[i], num[j]);
			DFS(i, depth + 1);
			swap(num[i], num[j]);
		}
	}
}

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		result = "";
		cin >> num >> change_cnt;

		if (num.size() < change_cnt) {
			num = num.size();
		}

		DFS(0, 0);

		cout << "#" << tc << " " << result << "\n";
	}

	return 0;
}