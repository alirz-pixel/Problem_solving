/* 2022-03-30  19:11
백준 10090번 Counting Inversion  ||  플래티넘 5
https://www.acmicpc.net/problem/10090


분야 : [ 분할정복, 세그먼트트리, 정렬, 자료구조 ]


시작시간 : **:**
종료시간 : **:**     걸린시간 : **분  |  시도횟수 : 2회
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> sorted;
long long ans = 0;

void merge_sort(int left, int mid, int right) {
	int k = left;
	int s1 = left;
	int s2 = mid + 1;

	long long cnt = 0;
	while (s1 <= mid && s2 <= right) {
		// 왼쪽 구간 넣기
		if (arr[s1] < arr[s2]) {
			sorted[k++] = arr[s1++];
			ans += cnt;
		}
		// 오른쪽 구간 넣기 (
		else {
			cnt++;
			sorted[k++] = arr[s2++];
		}
	}

	for (; s2 <= right; s2++) sorted[k++] = arr[s2];
	for (; s1 <= mid; s1++) {
		ans += cnt;
		sorted[k++] = arr[s1];
	}

	for (int i = left; i <= right; i++) arr[i] = sorted[i];
}

void merge(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		merge(left, mid);
		merge(mid + 1, right);
		merge_sort(left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;

	arr.assign(n, 0);
	for (auto &i : arr) {
		cin >> i;
	}

	sorted.assign(n, 0);
	merge(0, n - 1);

	cout << ans;

	return 0;
}