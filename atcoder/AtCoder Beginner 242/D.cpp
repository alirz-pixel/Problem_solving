#include <iostream>
#include <string>

using namespace std;

string S;

char g(char s, long long add) {
	return char('A' + (s - 'A' + add) % 3);
}

char f(long long t, long long k) {
	if (t == 0) return S[k];
	if (k == 0) return g(S[0], t);
	return g(f(t-1, k/2), k%2+1);
}

int main() {
	int q;
	
	cin >> S >> q;
	while (q--) {
		long long t, k;
		cin >> t >> k;
		cout << f(t, k-1) << "\n";
	}
  
  return 0;
}
