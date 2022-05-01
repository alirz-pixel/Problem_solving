#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Assignment {
	int day;
	int finish;
};

bool compare(Assignment& a, Assignment& b) {
	return a.finish > b.finish;
}

int main() {
	int n;
	cin >> n;

	vector<Assignment> assignments(n);
	for (auto& assignment : assignments) {
		cin >> assignment.day;
		cin >> assignment.finish;
	}

	sort(assignments.begin(), assignments.end(), compare);

	int next_start_time = INT_MAX;
	for (auto assignment : assignments) {
		next_start_time = min(next_start_time, assignment.finish);
		next_start_time -= assignment.day;
	}

	cout << next_start_time;

	return 0;
}
