/* 2022-04-10  23:41
백준 11657번  ||  골드 4
https://www.acmicpc.net/problem/11657

분야 : [ 벨만–포드 ]

시작시간 : **:**
종료시간 : **:**   ||  [ 시도횟수 : 4회  |  걸린시간 : **분 ]
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Edge {
	int u;
	int v;
	int cost;
};

struct Node {
	int next;
	int weight;

	Node(int _next, int _weight) { next = _next; weight = _weight; }
};

vector<vector<Node>> make_graph(vector<Edge>& edges, int N) {
	vector<vector<Node>> graph(N);

	for (auto edge : edges) {
		graph[edge.u].push_back( Node(edge.v, edge.cost) );
	}

	return graph;
}

void bellman_ford(vector<Edge>& edges, int N) {
	vector<vector<Node>> graph = make_graph(edges, N);
	vector<int> distance(N, INF);
	queue<int> q;

	q.push(0);
	distance[0] = 0;

	// 음의 cycle을 가지는지 판단하기 위해 N - 1번이 아닌 N번 돌음.
	for (int iter = 0; iter < N; iter++) {
		if (q.empty()) {
			break;
		}

		int size = q.size();
		vector<bool> node_distance_update(N);

		for (int i = 0; i < size; i++) {
			int front = q.front();
			q.pop();

			for (auto node : graph[front]) {
				if (distance[node.next] > distance[front] + node.weight) {
					distance[node.next] = distance[front] + node.weight;
					
					if (!node_distance_update[node.next]) {
						node_distance_update[node.next] = true;
						q.push(node.next);
					}
				}
			}
		}
	}

	if (!q.empty()) {
		cout << "-1";
	}
	else {
		for (int i = 1; i < N; i++) {
			int curr = distance[i];

			if (curr == INF) {
				cout << "-1\n";
			}
			else {
				cout << curr << "\n";
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M);
	for (auto& i : edges) {
		cin >> i.u >> i.v >> i.cost;
		i.u--;   i.v--;
	}

	bellman_ford(edges, N);

	return 0;
}
