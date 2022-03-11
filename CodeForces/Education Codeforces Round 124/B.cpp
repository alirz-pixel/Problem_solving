
#include <iostream>
 
using namespace std;
using lld = long long;
lld MAXV = 1000000000;
 
int main() {
	lld multi = 1;
	int cnt = 0;
	while (multi <= MAXV) {
		multi *= 3;
		cnt++;
	}
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		// 반례 없음
		if (cnt < n) {
			cout << "NO\n";
			continue;
		}
		
		multi = 1;
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << multi << " ";
			multi *= 3;
		}
		
		cout << "\n";
	}
	return 0;
}