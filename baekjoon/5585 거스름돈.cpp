/*  2022-02-25  20:22
백준 5585번 거스름돈 || 브론즈2
https://www.acmicpc.net/problem/5648

분류 : [그리디]


=======================[풀이]==========================
..
=======================================================


시작시간 : 20:15
종료시간 : 20:20       걸린시간 : 5분  ||  제출횟수 : 1회
*/


#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int pay, money[6] = { 500, 100, 50, 10, 5, 1 };;
	cin >> pay;

	int cnt = 0, change = 1000 - pay;
	for (auto i : money) {
		cnt += (change / i);
		change %= i;
	}

	cout << cnt;

	return 0;
}