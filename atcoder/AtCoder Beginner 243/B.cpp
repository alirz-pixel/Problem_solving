#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	long long N;
	cin >> N;

	vector<long long> A(N);
	vector<long long> B(N);


	for (auto& i : A) {
		cin >> i;
	}

	map<long long, long long> B_loc;
	for (long long i = 0; i < N; i++) {
		cin >> B[i];
		B_loc[B[i]] = i + 1;
	}


	// solve();
	long long first = 0, sec = 0;

	for (long long i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			first++;
		}
		else if (B_loc[A[i]]) {
			sec++;
		}
	}

	cout << first << "\n" << sec;

	return 0;
}