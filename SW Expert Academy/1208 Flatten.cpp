#include <algorithm>
#include <iostream>
#include <vector>
#define TESTCASE 10
#define MAX 100

using namespace std;

int main() {
	for (int tc = 1; tc <= TESTCASE; tc++) {
		int dump;
		cin >> dump;

		vector<int> height_cnt(MAX);
		int height_min = 100, height_max = 1;
		for (int i = 0; i < MAX; i++) {
			int cur_height;
			cin >> cur_height;

			height_cnt[cur_height]++;
			height_max = max(height_max, cur_height);
			height_min = min(height_min, cur_height);
		}

		while (dump > 0) {
			int movable_cnt = min(dump, min(height_cnt[height_max], height_cnt[height_min]));
			dump -= movable_cnt;

			height_cnt[height_max] -= movable_cnt;
			height_cnt[height_min] -= movable_cnt;

			height_cnt[height_max - 1] += movable_cnt;
			height_cnt[height_min + 1] += movable_cnt;

			if (height_cnt[height_max] == 0) {
				height_max--;
			}
			if (height_cnt[height_min] == 0) {
				height_min++;
			}
		}

		int ans = height_max - height_min;
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}