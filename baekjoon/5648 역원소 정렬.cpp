/*  2021-08-22  12:42
백준 5648번 역원소 정렬 || 실버4
https://www.acmicpc.net/problem/5648

분류 : [정렬]


=======================[풀이]==========================
..
=======================================================


시작시간 : 12:30
종료시간 : 12:40       걸린시간 : 10분  ||  제출횟수 : 1회
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void _reverse(long long& num) {
	long long ret = 0;
	int _pow = 1;

	// O(n) - 자릿수
	while (num != 0) {
		ret *= 10;
		ret += (num % 10);

		num /= 10;
	}
	
	num = ret;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	for (auto& i : arr) {
		cin >> i;
		_reverse(i);
	}

	sort(arr.begin(), arr.end(), less<long long>());

	for (auto i : arr) {
		cout << i << "\n";
	}
	
	return 0;
}