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

-------------------------------------------------
재재재 풀이 다익스트라 도전 (시간복자도 개선+)

위의 말대로 다익스트라는 한 정점에서 모든 정점으로의 최단경로 알고리즘이기 때문에
각 학생들의 집에서 x로 가는 것 또한 다익스트라 한 번으로 구할 수 있다.

여기에서 주의할 점이 하나 생기는데, 각 학생들의 집에서 x로 갈 떄에는 '역방향 그래프'를 사용해야 한다는 점이다.


그 이유는 이전 풀이에서 알 수 있는데
원래 각 학생들의 집에서 x로 가는 최단경로를 구할 떄에는 
1 -> x, 2 -> x, 3 -> x
이런 식으로 다익스트라를 여러번 사용해야 한다.

하지만 역방향 그래프를 이용하게 된다면
1 <- x, 2 <- x, 3 <- x
이런 식으로 변하게 되기 때문에 한번의 다익스트라 사용으로 각 학생들의 집에서 x로 갈 수 있게 되는 것이다.


시작 시간 : *:** (재풀이이기 때문에 무의미)
종료 시간 : *:** (재풀이이기 때문에 무의미)
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

    vector<vector<pair<int, int>>> graph(n + 1), reverse_graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        graph[v1].push_back({cost, v2});
        reverse_graph[v2].push_back({cost, v1});
    }

    int max = 0;
    vector<int> result(n + 1), Rresult(n + 1);
    dijkstra(graph, x, -1, n, result);
    dijkstra(reverse_graph, x, -1, n, Rresult);
    
    for (int i = 1; i <= n; i++)
        if (max < result[i] + Rresult[i])
            max = result[i] + Rresult[i];

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