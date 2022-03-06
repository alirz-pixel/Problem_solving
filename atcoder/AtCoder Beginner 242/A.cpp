#include <iostream>

using namespace std;

int main() {
	double A, B, C, X;
	cin >> A >> B >> C >> X;

	double ans = 0;
	if (X <= A) {
		ans = 1;
	}
	else if (!(A + 1 <= X && X <= B)) {
		ans = 0;
	}
	else {
		ans = double(C / (B - A));
	}

	cout << ans;
}