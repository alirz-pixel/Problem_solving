/*  2021-08-22  12:14
백준 18353번 병사 배치하기 || 실버2
https://www.acmicpc.net/problem/18353

분류 : [LIS]


=======================[풀이]==========================
입력을 반대로 받아 단순히 LIS 를 구하면 되는 문제이다.
=======================================================


시작시간 : 12:00
종료시간 : 12:09       걸린시간 : 9분  ||  제출횟수 : 1회
*/


// 시작시간  |  12:00
// 종료시간  |  12:09

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = N - 1; i >= 0; i--) {
		cin >> arr[i];
	}

	// solve() - LIS n(log n);
	vector<int> _LIS(1);
	_LIS[0] = 0;

	int lisCnt, ret = 0;
	for (auto i : arr) {
		lisCnt = lower_bound(_LIS.begin(), _LIS.end(), i) - _LIS.begin();

		if (_LIS.size() <= lisCnt) {
			_LIS.push_back(i);
		} else if (_LIS[lisCnt] > i) {
			_LIS[lisCnt] = i;
		}

		ret = max(ret, lisCnt);
	}

	cout << N - ret;
	return 0;
}