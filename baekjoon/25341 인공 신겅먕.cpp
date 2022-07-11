#include <iostream>
#include <vector>

using namespace std;
using lld = long long;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<lld>> weight(m, vector<lld>(n + 2));
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;

		vector<int> p(c);
		for (auto& j : p) {
			cin >> j;
		}

		for (auto j : p) {
			cin >> weight[i][j];
		}
		cin >> weight[i][n + 1];
	}


	vector<lld> A(n + 2);
	for (int i = 0; i < m; i++) {
		int output_weight;
		cin >> output_weight;

		for (int j = 1; j <= n + 1; j++) {
			A[j] += output_weight * weight[i][j];
		}
	}
	int output_bias;
	cin >> output_bias;
	A[n + 1] += output_bias;


	vector<int> input_layer(n + 1);
	for (int i = 0; i < q; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input_layer[j];
		}

		lld y_hat = 0;
		for (int j = 1; j <= n; j++) {
			y_hat += input_layer[j] * A[j];
		}
		cout << y_hat + A[n + 1] << "\n";
	}

	return 0;
}
