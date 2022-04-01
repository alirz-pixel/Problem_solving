#include <iostream>

#include <vector>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		stack<char> st;
		vector<bool> alpha(26);

		long long cnt = 0;
		int index = 0;
		for (auto i : str) {
			if (alpha[i - 'a']) {
				while (!st.empty() && st.size() != 1) {
					cnt++;
					alpha[st.top() - 'a'] = false;
					st.pop();
				}

				alpha[st.top() - 'a'] = false;
				st.pop();
			}
			else {
				alpha[i - 'a'] = true;
				st.push(i);
			}
		}

		cout << cnt + st.size() << "\n";
	}

	return 0;
}