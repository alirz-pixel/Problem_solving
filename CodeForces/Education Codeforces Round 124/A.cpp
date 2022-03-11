#include <iostream>
#include <cmath>
#include <map>
 
using namespace std;
 
using lld = long long;
 
int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
 
		cout << lld(pow(2, n)) - 1 << "\n";
	}
	
	
	return 0;
}