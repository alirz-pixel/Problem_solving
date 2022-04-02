#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define INF INT_MAX

using namespace std;

struct Edge {
	int u;
	int v;
	int w;
};

struct Node {
	int next;
	int weight;

	Node(int _next, int _weight) { next = _next; weight = _weight; }
};

struct compare {
	bool operator()(const Node& n1, const Node& n2) {
		return n1.weight > n2.weight;
	}
};

vector<vector<Node>> make_graph(vector<Edge> edge, int V) {
	vector<vector<Node>> graph(V);
	for (auto i : edge) {
		graph[i.u].push_back(Node(i.v, i.w));
	}

	return graph;
}

void dijkstra(vector<Edge> edge, int V, int K) {
	vector<vector<Node>> graph = make_graph(edge, V);

	vector<int> distance(V, INF);
	priority_queue<Node, vector<Node>, compare> min_node;
	vector<bool> check(V);

	distance[K] = 0;
	min_node.push(Node(K, 0));

	while (!min_node.empty()) {
		Node top = min_node.top();
		min_node.pop();

		if (check[top.next]) continue;
		check[top.next] = true;

		for (auto i : graph[top.next]) {
			if (check[i.next]) continue;

			if (distance[i.next] > top.weight + i.weight) {
				distance[i.next] = top.weight + i.weight;
				min_node.push(Node(i.next, top.weight + i.weight));
			}
		}
	}

	for (auto d : distance) {
		if (d == INF) {
			cout << "INF\n";
		}
		else {
			cout << d << "\n";
		}
	}
}

int main() {
	int V, E, K;
	cin >> V >> E >> K;
	K--;

	vector<Edge> edges(E);
	for (Edge& edge : edges) {
		cin >> edge.u >> edge.v >> edge.w;

		edge.u--; 
		edge.v--;
	}

	dijkstra(edges, V, K);

	return 0;
}