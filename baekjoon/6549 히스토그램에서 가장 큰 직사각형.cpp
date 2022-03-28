/* 2022-03-29  00:15
백준 6548번 히스토그램에서 가장 큰 직사각형 || 플래티넘 5
https://www.acmicpc.net/problem/6549


분야 : [세그먼트트리, 스택, 분할 정복]


시작시간 : **:**
종료시간 : **:**  || 총 시도횟수 : 2번,  ** (미흡)
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

vector<int> seg;
lld max_area;

int init(vector<lld>& arr, int node, int left, int right) {
	if (left == right) {
		return seg[node] = left;
	}

	int mid = (left + right) / 2;
	int l_idx = init(arr, node * 2, left, mid);
	int r_idx = init(arr, node * 2 + 1, mid + 1, right);

	return seg[node] = arr[l_idx] < arr[r_idx] ? l_idx : r_idx;
}

int query(vector<lld>& arr, int node, int left, int right, int start, int end) {
	if (right < start || left > end) {
		return -1;
	}

	if (start <= left && right <= end) {
		return seg[node];
	}

	int mid = (left + right) / 2;

	int l_idx = query(arr, node * 2, left, mid, start, end);
	int r_idx = query(arr, node * 2 + 1, mid + 1, right, start, end);

	if (l_idx == -1) return r_idx;
	else if (r_idx == -1) return l_idx;
	return arr[l_idx] < arr[r_idx] ? l_idx : r_idx;
}

void div_loop(vector<lld>& arr, int left, int right) {
	if (left <= right) {
		int cut_idx = query(arr, 1, 0, arr.size() - 1, left, right);
		max_area = max(max_area, arr[cut_idx] * (right - left + 1));
		
		div_loop(arr, left, cut_idx - 1);
		div_loop(arr, cut_idx + 1, right);
	}
}

int main() {
	int n;

	while (cin >> n && n != 0) {
		vector<lld> arr(n);
		for (auto& i : arr) {
			cin >> i;
		}

		seg.assign(n * 4, 0);

		max_area = 0;

		init(arr, 1, 0, n - 1);
		div_loop(arr, 0, n - 1);

		cout << max_area << "\n";
	}

	return 0;
}