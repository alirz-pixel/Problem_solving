#include <iostream>
#include <string>
#include <set>

using namespace std;

void print_ans(int tc, string ans) {
	cout << "#" << tc << " " << stoi(ans, NULL, 16) << "\n";
}

int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int n, k;
		cin >> n >> k;

		string nums;
		cin >> nums;

		set<string> passwd;
		int pos = 0;

		// 외부 회전 횟수
		for (int i = 0; i < n / 4; i++) {
			// 문자열 생성 => 4개
			int pos_tmp = pos;
			for (int j = 0; j < 4; j++) {
				string make_str;

				for (int k = 0; k < n / 4; k++) {
					make_str += nums[pos_tmp];
					pos_tmp = (pos_tmp + 1) % n;
				}

				passwd.insert(make_str);
			}

			pos = ((pos - 1) + n) % n;
		}

		auto ans = passwd.begin();
		advance(ans, (passwd.size() - k));

		print_ans(tc, *ans);
	}

	return 0;
}