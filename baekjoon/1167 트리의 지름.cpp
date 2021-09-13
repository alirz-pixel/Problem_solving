/*  2021-09-12  6:20
백준 1167번 트리의 지름  ||  골드3
https://www.acmicpc.net/problem/1167







시작시간 : *:**
종료시간 : *:**     제출시도 : 4회  ||  
*/



#include <iostream>
#include <vector>

using namespace std;

pair<int, int> DFS(vector<vector<pair<int, int>>>& graph, int start, int pre, int sum, int maxIndex);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int v, vertex, connectV, weight;
	cin >> v;

	vector<vector<pair<int, int>>> graph(v+1);
	for (int i = 0; i < v; i++)
	{
		cin >> vertex;
		while (1)
		{
			cin >> connectV;
			if (connectV == -1)
				break;

			cin >> weight;
			graph[vertex].push_back( {connectV, weight} );
		}
	}


	// solve();
	pair<int, int> result, temp;
	result = DFS(graph, 1, -1, 0, -1);
	temp = DFS(graph, result.second, -1, 0, -1);

	if (result.first > temp.first)
		cout << result.first;
	else
		cout << temp.first;

	return 0;
}


pair<int, int> DFS(vector<vector<pair<int, int>>>& graph, int start, int pre, int sum, int maxIndex)
{
	pair<int, int> temp, max = {sum, start};
	for (auto i : graph[start])
		if (i.first != pre)
		{
			temp = DFS(graph, i.first, start, sum+i.second, max.second);
			if (max.first < temp.first)
			{
				max.first = temp.first;
				max.second = temp.second;
			}
		}

	return max;
}