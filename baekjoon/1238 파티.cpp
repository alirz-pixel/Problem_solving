/*
백준 1238 파티 || 골드 3
https://www.acmicpc.net/problem/1238



문제를 처음보았을 때, 다익스트라 라기보단
플로이드 와샬로 풀면 더 좋지 않을까라는 생각이 들게 되었다.
(다익스트라의 경우엔 여러번을 반복해야되기 때문)

문제를 다 풀고나서 미쳐 생각치 못한 부분이 있었는데
바로 시간복잡도 부분이었다.

플로이드 와샬은 for문을 3개나 돌기 때문에 O(n^3)이 걸리게 된다.
현재 문제에서의 정점의 개수는 1000개 이므로
플로이드 와샬로 풀게되면 당연히 시간복잡도 측면에서 터지게 된다.
(앞으로 조심할 것)

-----------------------------------------------
재풀이 다익스트라 도전

이번에도 총 제출횟수는 2번인데
그 이유가 인접 행렬로 구현했기 때문이다.

인접 행렬의 경우, dist[vertex]를 판단하기 위해선
정점의 수만큼 반복해야 하는데 이것이 시간 초과가 나게 한 원인인 것 같다.

------------------------------------------------
재재 풀이 다익스트라 도전 (시간복잡도 개선)

다익스트라가 한 정점에서 모든 정점으로의 최단경로 알고리즘을 잊고 있어서 그런지
다익스트라를 무의미하게 여러번 돌렸던 점을 개선하였다.

==> x에서 각각 학생의 집으로 갈 떄, 다익스트라를 한 번만 사용해도 됨


시작 시간 : 5:03
종료 시간 : 5:23
*/



#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end, int num, vector<int> &result);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, x, v1, v2, cost;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        graph[v1].push_back({cost, v2});
    }

    int max = 0;
    vector<int> result(n + 1);
    dijkstra(graph, x, -1, n, result);
    for (int i = 1; i <= n; i++)
    {
        if (i == x) continue;

        result[i] = dijkstra(graph, i, x, n, result) + result[i];

        if (max < result[i] && result[i] < INF)
            max = result[i];
    }

    cout << max;

    return 0;
}


int dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end, int num, vector<int> &result)
{
    vector<bool> visited(num + 1, false);
    vector<int> dist(num + 1, INF);

    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    int vertex, nextv;
    while(!pq.empty())
    {
        vertex = pq.top().second;
        pq.pop();

        if (visited[vertex]) continue;
        visited[vertex] = true;

        for (int i = 0; i < graph[vertex].size(); i++)
        {
            nextv = graph[vertex][i].second;

            if (dist[nextv] > dist[vertex] + graph[vertex][i].first)
            {
                dist[nextv] = dist[vertex] + graph[vertex][i].first;
                pq.push({-dist[nextv], nextv});
            }
        }
    }

    if (end == -1)
    {
        for (int i = 1; i <= num; i++)
            result[i] = dist[i];

        return -1;
    }

    return dist[end];
}