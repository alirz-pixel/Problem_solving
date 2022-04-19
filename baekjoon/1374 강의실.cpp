#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct LectureInfo {
	int num;
	int start;
	int end;
};

bool compare(LectureInfo& a, LectureInfo& b) {
	return a.start < b.start;
}

int main() {
	int n;
	cin >> n;

	int temp;
	vector<LectureInfo> lectures(n);
	for (auto& lecture : lectures) {
		cin >> lecture.num >> lecture.start >> lecture.end;
	}

	sort(lectures.begin(), lectures.end(), compare);

	// 최소 강의실의 수에 대한 우선순위 큐 제작
	priority_queue<int, vector<int>, greater<int>> lecture_end_time;
	lecture_end_time.push(lectures[0].end);
	for (int i = 1; i < lectures.size(); i++) {
		if (lectures[i].start >= lecture_end_time.top()) {
			lecture_end_time.pop();
		}

		lecture_end_time.push(lectures[i].end);
	}

	cout << lecture_end_time.size() << "\n";
	return 0;
}
