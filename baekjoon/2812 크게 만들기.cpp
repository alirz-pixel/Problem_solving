/*  2022-03-06  14:57
백준 2812번 크게 만들기 || 골드4
https://www.acmicpc.net/problem/2812

분류 : [그리디]


=======================[풀이]==========================
..
=======================================================


*/

#include <iostream>
#include <deque>

using namespace std;

int N, K;

void solve(string& s) {
	deque<char> dq;

	int del_cnt = 0;
	for (auto i : s) {
		while (!dq.empty() && dq.back() < i && del_cnt < K) {
			dq.pop_back();
			del_cnt++;
		}

		dq.push_back(i);
	}

	for (int i = 0; i < N - K; i++) {
		cout << dq[i];
	}
}


int main() {
	cin >> N >> K;

	string s;
	cin >> s;


	solve(s);

	return 0;
}