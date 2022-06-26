#include <iostream>
#define MAX 1000000

using namespace std;
bool era[MAX];

int main() {
	for (int i = 2; i <= MAX; i++) {
		if (era[i]) {
			continue;
		}

		cout << i << " ";
		for (int j = i + i; j <= MAX; j += i) {
			era[j] = true;
		}
	}
}