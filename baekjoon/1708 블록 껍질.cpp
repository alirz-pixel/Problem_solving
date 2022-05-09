#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using lld = long long;

struct Point {
	lld x, y;

	bool operator < (const Point& a) {
		if (y == a.y) {
			return x < a.x;
		}

		return y < a.y;
	}
};

vector<Point> points;
int n;

int ccw(Point& a, Point& b, Point& c) {
	lld plus = (a.x * b.y) + (b.x * c.y) + (c.x * a.y);
	lld minus = (b.x * a.y) + (c.x * b.y) + (a.x * c.y);

	lld ret = plus - minus;
	// 양수 : 반시계
	if (ret > 0) {
		return 1;
	}
	// 음수 : 시계
	else if (ret < 0) {
		return -1;
	}
	// 0 : 직선
	return 0;
}

lld dist(Point& a, Point& b) {
	lld dx = b.x - a.x;
	lld dy = b.y - a.y;

	return dx * dx + dy * dy;
}

bool cmp(Point& a, Point& b) {
	lld cost = ccw(points[0], a, b);
	if (cost) return cost > 0;
	return dist(points[0], a) < dist(points[0], b);
}

int convexhull() {
	stack<int> candidate;
	candidate.push(0);
	candidate.push(1);

	for (int next = 2; next < n; next++) {
		while (candidate.size() >= 2) {
			int second = candidate.top(); candidate.pop();
			int first = candidate.top();

			if (ccw(points[first], points[second], points[next]) > 0) {
				candidate.push(second);
				break;
			}
		}

		candidate.push(next);
	}

	return candidate.size();
}

int main() {
	cin >> n;

	points.assign(n, { 0, 0 });
	for (auto& point : points) {
		cin >> point.x >> point.y;
	}
	sort(points.begin(), points.end());
	sort(points.begin() + 1, points.end(), cmp);

	cout << convexhull();

	return 0;
}
