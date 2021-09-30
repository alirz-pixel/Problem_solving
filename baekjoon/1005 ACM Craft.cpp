/*  2021-09-30  4:20
백준 1005번 ACM Craft  ||  골드3
https://www.acmicpc.net/problem/1005




선배님꼐서 이 문제가 위상정렬을 이용해서 푸는 문제라 알려주셔서
위상정렬 알고리즘을 처음 검색하여 풀음. (위상정렬을 구현하는 소스코드는 참고하지 않고, 문제를 풀었음.)

(위상정렬은 사이클이 존재하는 경우 사용할 수 없다.)
위상정렬이 가능한 이유 :
 문제의 조건에서 '건설순서는 모든 건물이 건설 가능하도록 주어진다.' 라는 내용이 있는데
 만약, 문제의 입력에서 사이클이 존재하게 될 경우
  X 건물은 Y 건물을 지은 다음에 건설이 가능하며,
  Y 건물은 X 건물을 지은 다음에 건설이 가능하다
 라는 모순이 발생하게 되어 사이클이 존재할 수가 없게 되는 것이다.


시작시간 : 3:53
종료시간 : 4:19     제출시도 : 1회  ||  걸린시간 : 26분
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& buildTime, vector<int>& connect, int n, int w);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int t, n, k, sv, ev, w;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		vector<vector<int>> graph(n);
		vector<int> buildTime(n), connect(n);
		for (auto &i : buildTime)
			cin >> i;

		while (k--) {
			cin >> sv >> ev;
			sv--; ev--;

			// DAG 및 위상정렬을 위한 세팅
			graph[sv].push_back(ev);
			connect[ev]++;
		}
		cin >> w;
		w--;

		topologicalSort(graph, buildTime, connect, n, w);
	}
	return 0;
}


void topologicalSort(vector<vector<int>>& graph, vector<int>& buildTime, vector<int>& connect, int n, int w)
{
	vector<int> creatTime(n);
	vector<bool> v(n);
	queue<int> q;

	for (int i = 0; i < n; i++)
		if (connect[i] == 0)
			q.push(i);

	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();

		if (v[front]) continue;
		v[front] = true;
		creatTime[front] += buildTime[front];

		for(auto i : graph[front]) {
			connect[i]--;
			creatTime[i] = max(creatTime[front], creatTime[i]);
		}

		for (int i = 0; i < n; i++)
			if (connect[i] == 0 && v[i] == false)
				q.push(i);
	}

	cout << creatTime[w] << "\n";
}