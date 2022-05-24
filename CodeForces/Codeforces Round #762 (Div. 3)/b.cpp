#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main(void) {

	int tc;
	cin >> tc;

	while (tc--)
	{
		ll n;
		cin >> n;

		int cnt = 1;
		for (ll i = 2; i*i <= n; i++) {
			cnt++;
			if (i*i <= n/i) {
				cnt++;
			}
			if (i*i <= n / i / i / i / i) {
				cnt--;
			}
		}

		cout << cnt << "\n";
	}
	
}
