#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int  main() {
	long long  t;
	cin >> t;

	while (t--) {
		long long  n, k;
		cin >> n >> k;

		map<long long , long long > m;
		for (long long  i = 0; i < n; i++) {
			long long  temp;
			cin >> temp;

			m[temp]++;
		}

		long long  prev = -2;
		long long  maxv = 0;
		long long  l;
		pair<long long , long long > result = { -1,-1 };
		for (auto i : m) {
			if (i.second < k) continue;
			if (prev+1 != i.first) {
				l = i.first;
			}
			if (maxv <= i.first - l) {
				maxv = i.first - l;
				result = { l,i.first };
			}
			prev = i.first;
		}
		if (result.first == -1) {
			cout << "-1\n";
		}
		else {
			cout << result.first << " " << result.second << "\n";
		}
	}

	return 0;
}
