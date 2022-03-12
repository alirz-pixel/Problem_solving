#include <iostream>

using namespace std;

int main() {
	int V, A, B, C;
	cin >> V >> A >> B >> C;

	while (1) {
		if (V - A < 0) {
			cout << "F";
			break;
		}
		V -= A;

		if (V - B < 0) {
			cout << "M";
			break;
		}
		V -= B;

		if (V - C < 0) {
			cout << "T";
			break;
		}
		V -= C;
	}
	

	return 0;
}