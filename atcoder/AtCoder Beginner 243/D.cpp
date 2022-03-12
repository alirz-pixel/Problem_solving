#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	long long N, X;
	cin >> N >> X;

	string S;
	cin >> S;
	

	// 1. 스택에 담는다
	// U가 이전 연산을 취소한다고 생각하면 됨.
	// 단 UUUURLRL
	deque<char> st;
	for (auto i : S) {
		if (i != 'U') {
			st.push_back(i);
		}

		else {
			if (st.empty()) {
				X /= 2;
			}
			else {
				st.pop_back();
			}
		}
	}

	for (auto front : st) {
		if (front == 'L') {
			X *= 2;
		}
		else {
			X = (2 * X) + 1;
		}
	}

	cout << X;

	return 0;
}