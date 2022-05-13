#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	int one = 987654321;
	int two = 987654321;
	for (auto& i : arr) {
		cin >> i;
		if (i < one) {
			two = one;
			one = i;
		}
		else if(i<two)
		{
			two = i;
		}
	}

	int minv = (one / 2 + one % 2) +(two/2+two%2);
	for (int i = 1;i < n;i++) {
		int a = max(arr[i - 1], arr[i]);
		int b = min(arr[i - 1], arr[i]);

		if (b * 2 <= a) {
			minv = min(minv, a / 2 + a % 2);
		}
		else
		{
			int c = b * 2 - a;
			minv = min(minv, b - c / 3);
		}

	}

	for (int i = 1;i < n - 1;i++) {
		int c = max(arr[i - 1], arr[i + 1]) - min(arr[i - 1], arr[i + 1]);
		minv = min(minv, min(arr[i - 1], arr[i + 1])+c/2+c%2);
	}
	cout << minv;
	return 0;
}
