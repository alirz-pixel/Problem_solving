#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int ans = -1;

		long long first, result;
		cin >> first >> result;

		stack<int> st;
		bool is_true = true;
		while (first != 0) {
			int result_cur = result % 10;
			result /= 10;

			int first_cur = first % 10;
			first /= 10;

			//cout << first_cur << "\n";
			if (first_cur > result_cur) {
				if (result == 0) {
					is_true = false;
					break;
				}

				result_cur = (result_cur + (result % 10) * 10);
				result /= 10;

				if (result_cur > 18 || result_cur - first_cur < 0) {
					is_true = false;
					break;
				}
				st.push(result_cur - first_cur);
				continue;
			}

			st.push(result_cur - first_cur);
		}

		// cout << ans << "\n";
		if (!is_true) {
			cout << -1 << "\n";
		}
		else {
			while (result) {
				st.push(result % 10);
				result /= 10;
			}

			// 맨 앞의 0 제거하기
			while (!st.empty() && st.top() == 0) {
				st.pop();
			}

			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << "\n";
		}
	}

	return 0;
}
