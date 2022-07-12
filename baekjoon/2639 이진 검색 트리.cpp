#include <iostream>
#include <vector>

using namespace std;
vector<int> tree;

// left is root
void binary_tree(int left, int right) {
	if (left > right) {
		return;
	}

	bool is_right_sub_tree = false;
	for (int i = left + 1; i <= right; i++) {
		if (tree[left] < tree[i]) {
			binary_tree(left + 1, i - 1);
			binary_tree(i, right);
			is_right_sub_tree = true;
			break;
		}
	}

	if (!is_right_sub_tree) {
		binary_tree(left + 1, right);
	}

	cout << tree[left] << "\n";
}

int main() {
	int node;
	while (cin >> node) {
		tree.push_back(node);
	}

	binary_tree(0, tree.size() - 1);
	return 0;
}
