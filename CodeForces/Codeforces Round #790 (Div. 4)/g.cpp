#include <iostream>
#include <vector>
#include<string>

using namespace std;

int n;
int cnt;
typedef pair<int, int> pii;



pii solve(vector<vector<int>>& graph, string& s, int now) {
	pii wb = { 0,0 };
	for (auto v : graph[now]) {
		pii tmp = solve(graph, s, v);
		wb.first += tmp.first;
		wb.second += tmp.second;
	}

	wb.first += s[now - 1] == 'W';
	wb.second += s[now - 1] == 'B';

	if (wb.first == wb.second)
		cnt++;
	return wb;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		cnt = 0;
		vector<vector<int>> graph(n + 1);
		string s;
		for (int i = 2; i <= n; i++) {
			int temp;
			cin >> temp;

			graph[temp].push_back(i);
		}
		cin >> s;

		solve(graph, s, 1);
		cout << cnt << "\n";
	}

	return 0;
}
