#include <iostream>
#define MAX 300000

using namespace std;

bool is_not_prime[MAX + 1] = { 0, };
int main() {
	bool calc_prime = false;
	for (int i = 6; i <= MAX; i += (calc_prime ? 2 : 5)) {
		for (int j = i * 2; j <= MAX; j += i) {
			is_not_prime[j] = true;
		}

		calc_prime = !calc_prime;
	}

	int n;

	while (cin >> n && n != 1) {
		cout << n << ": ";

		bool calc_prime = false;
		int i = 6;
		while (i <= n) {
			if (!(n % i) && !is_not_prime[i]) {
				cout << i << " ";
			}

			i += (calc_prime ? 5 : 2);
			calc_prime = !calc_prime;
		}
		cout << "\n";
	}
	return 0;
}
