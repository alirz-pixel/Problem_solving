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
#include <cmath>
#include <climits>

using namespace std;

long long n;
long long max_area;
vector<pair<long long, long long>> seg;

// minV, min_index;
pair<long long, long long> init(vector<long long>& height, long long node, long long left, long long right) {
	if (left == right) {
		seg[node].second = left;
		seg[node].first = height[left];
		return seg[node];
	}

	long long mid = (left + right) / 2;

	return seg[node] = min(init(height, node * 2, left, mid),
		init(height, node * 2 + 1, mid + 1, right));
}

// first : minV;
// second : min_index;
pair<long long, long long> query(long long node, long long start, long long end, long long find_left, long long find_right) {
	if (find_right < start || end < find_left) {
		return { LLONG_MAX, LLONG_MAX };
	}

	if (find_left <= start && end <= find_right) {
		return { seg[node].first, seg[node].second };
	}

	long long mid = (start + end) / 2;
	pair<long long, long long> minV = min(query(node * 2, start, mid, find_left, find_right), query(node * 2 + 1, mid + 1, end, find_left, find_right));

	return minV;
}

void loop(long long left, long long right) {
	if (left <= right) {
		pair<long long, long long> tmp = query(1, 0, n - 1, left, right);
		long long cut_mid = tmp.second;

		if (tmp.first != LLONG_MAX) {
			max_area = max(max_area, tmp.first * (right - left + 1));
		}

		if (left != right) {
			loop(left, cut_mid - 1);
			loop(cut_mid + 1, right);
		}
	}
}

int main() {
	while ((cin >> n) && n != 0) {
		vector<long long> height(n);

		for (auto& i : height) {
			cin >> i;
		}

		seg.assign(n * 4, { 0, 0 });
		init(height, 1, 0, n - 1);

		max_area = LLONG_MIN;
		loop(0, n - 1);

		cout << max_area << "\n";
	}
	return 0;
}