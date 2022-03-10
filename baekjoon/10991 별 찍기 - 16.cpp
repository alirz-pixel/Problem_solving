#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		// n - i 띄어쓰기
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		
		// 각 줄마다 2n-1 출력
		for (int j = 1; j <= (2 * i) - 1; j++) {
			if (j % 2 == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}