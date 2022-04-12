#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

lld gcd(lld a, lld b) {
	if (a % b == 0) {
		return b;
	}

	return gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<lld> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		lld odd_gcd = a[0];
		for (int odd = 2; odd < n; odd += 2) {
			odd_gcd = gcd(odd_gcd, a[odd]);
		}

		lld even_gcd = a[1];
		for (int even = 3; even < n; even += 2) {
			even_gcd = gcd(even_gcd, a[even]);
		}

		lld result = even_gcd;
		bool find_result = true;
		for (int odd = 0; odd < n; odd += 2) {
			if (a[odd] % even_gcd == 0) {
				find_result = false;
				break;
			}
		}

		if (!find_result) {
			result = odd_gcd;
			for (int even = 1; even < n; even += 2) {
				if (a[even] % odd_gcd == 0) {
					result = 0;
					break;
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}