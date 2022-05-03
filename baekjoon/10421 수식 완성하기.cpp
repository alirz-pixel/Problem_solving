#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

vector<lld> lines_length; // 처음과 끝을 제외한 나머지 부분들은 length 로 사용
vector<lld> mid_ans;
vector<bool> usable_nums;
vector<lld> only_usable_nums;
lld ans = 0;
lld n, k;

lld use_usable(lld num) {
	lld _digit = 0;

	while (num) {
		if (!usable_nums[num % 10]) {
			return -1;
		}

		num /= 10;
		_digit++;
	}

	return _digit;
}

// 작성이 끝나면 해당 숫자들에 대해 두번쨰 숫자도 backtracking으로 작성한다.
void fill_second_line(const lld& first_line_num, lld second_line_num, lld depth) {
	if (depth == lines_length[1]) {
		// cout << second_line_num << "\n";
		lld total = 0;
		lld ten = 1;

		for (auto i : mid_ans) {
			total += (i * ten);
			ten *= 10;
		}

		lld _digit = use_usable(total);
		if (_digit == lines_length[n - 1]) {
			ans++;
			// cout << "total : " << total << "\n\n";
		}
		return;
	}

	for (auto i : only_usable_nums) {
		lld tmp_ans = first_line_num * i;
		lld _digit = use_usable(tmp_ans);
		if (_digit != lines_length[depth + 2]) {
			continue;
		}
		mid_ans[depth] = tmp_ans;

		fill_second_line(first_line_num, (second_line_num * 10) + i, depth + 1);
	}
}

// 첫번째 숫자를 backtracking으로 작성한다.
void fill_first_line(lld first_line_num, lld depth) {
	if (lines_length[0] == depth) {
		// cout << sum << "\n";

		// 두번째 숫자 정하기
		fill_second_line(first_line_num, 0, 0);
		return;
	}

	for (auto i : only_usable_nums) {
		fill_first_line(first_line_num * 10 + i, depth + 1);
	}
}

int main() {
	cin >> n;

	lines_length.assign(n, 0);
	mid_ans.assign(n - 3, 0);
	usable_nums.assign(10, false);

	for (auto& line : lines_length) {
		cin >> line;
	}
	
	cin >> k;
	only_usable_nums.assign(k, 0);
	for (lld i = 0; i < k; i++) {
		lld usable_num;
		cin >> usable_num;
		usable_nums[usable_num] = true;
		only_usable_nums[i] = usable_num;
	}

	fill_first_line(0, 0);

	cout << ans;

	return 0;
}
