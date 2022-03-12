#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
	string S;
	int N;
	cin >> N;

	// y가 같은 아이들끼리 x값을 비교하는데;
	// 작은 놈이 R이고 큰 놈이 L이면 충돌;

	int x, y;
	map<int, vector<pair<int, int>>> loc;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		loc[y].push_back({ x, i });
	}
	cin >> S;

	bool is_true = false;
	for (auto& i : loc) {
		//cout << i.first << "\n";
		// 이것만 확인
		if (i.second.size() > 1) {
			sort(i.second.begin(), i.second.end(), less<pair<int, int>>());

			// 투 포인터
			int left = 0;
			int right = i.second.size() - 1;

			while (left < right) {
				if (S[i.second[left].second] == 'R' && S[i.second[right].second] == 'L') {
					is_true = true;
					break;
				}
				// left 증가
				if (S[i.second[left].second] != 'R') {
					left++;
					continue;
				}

				if (S[i.second[right].second] != 'L') {
					right--;
					continue;
				}
			}

			if (is_true) {
				break;
			}
		}
	}

	if (is_true) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}