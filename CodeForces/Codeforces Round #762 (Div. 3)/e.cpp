#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
		vector < ll > cnt(n + 1);
		stack<pii> st;
		ll total = 0;
		ll num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			cnt[num]++;
		}

		for (int i = 0; i <= n; i++) {
			if (total == -1) {
				cout << "-1 ";
				continue;
			}
			else
				cout << total + cnt[i] << " ";

			if (cnt[i] > 0) {
				if (cnt[i] > 1)
					st.push({ i,cnt[i] - 1 });
			}
			else if (st.empty()) {
				total = -1;
			}
			else {
				auto tmp = st.top(); st.pop();
				total += i - tmp.first;
				tmp.second--;
				if (tmp.second) {
					st.push(tmp);
				}
			}
		}
		cout << "\n";
	}
	
}
