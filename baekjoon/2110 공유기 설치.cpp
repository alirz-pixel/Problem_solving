/* 2022-03:17  23:24
백준 2110번 공유기 설치 || 골드 5
https://www.acmicpc.net/problem/2110

분야 : [ 이분탐색, 매개변수 탐색 ]

================================
[ 오답 사유 ]
 - 매개변수 탐색에 대한 이해도 부족.
 - 이분탐색에 대한 이해도 부족.
================================

시작시간 : **:**
종료시간 : **:**   ||  [ 시도횟수 : 2회  |  걸린시간 : **분 ]
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;
	

	vector<int> arr(N);
	for (auto& i : arr) {
		cin >> i;
	}


	sort(arr.begin(), arr.end(), less<int>());

	vector<int> dist(N - 1);
	for (int i = 0; i < N - 1; i++) {
		dist[i] = abs(arr[i + 1] - arr[i]);
	}

	int l = 1;
	int r = 1000000000;

	int ans = 0;
	while (l <= r) {
		int mid = l + ((r - l) / 2) ;

		int installation_cnt = 1;
		int sum = 0;
		for (auto i : dist) {
			sum += i;

			if (sum >= mid) {
				sum = 0;
				installation_cnt++;
			}
		}

		// 더 많이 설치되었다.
		// 제한 거리를 늘린다.
		if (installation_cnt >= C) {
			ans = max(mid, ans);
			l = mid + 1;
		}
		// 적게 설치 되었다.
		// 제한 거리를 좁힌다.
		else {
			r = mid - 1;
		}
	}

	cout << ans;

	return 0;
}