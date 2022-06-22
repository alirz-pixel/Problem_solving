#include <algorithm>
#include <iostream>
#include <vector>
#define MIN -1000000000

using namespace std;
using lld = long long;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio  (0);

	int n;
	cin >> n;

	vector<pair<lld, lld>> line(n);
	for (auto& i : line) {
		cin >> i.first >> i.second;
	}
	sort(line.begin(), line.end());

	lld draw_line = 0;
	lld end = MIN;
	for (auto i : line) {
		if (i.second <= end) {
			continue;
		}

		if (i.first > end) {
			draw_line += i.second - i.first;
		}
		else {
			draw_line += i.second - end;
		}
		end = i.second;
	}

	cout << draw_line;

	return 0;
}