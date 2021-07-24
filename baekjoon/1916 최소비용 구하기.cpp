/*
백준 1916 최소비용 구하기 || 골드 5
https://www.acmicpc.net/problem/1916



다익스트라를 이용한 최소비용 구하기는 이미 풀었지만
전에는 이것을 입접행렬로 구현하여 풀었었다.

하지만 이 방식은 시간 초과가 발생할 우려가 있다는 피드백을 듣게 되어
인접 리스트를 이용한 방식으로 재시도 하였다.

시작시간 : 2:06
종료시간 : 2:20     총 소요시간 : 14  || 총 시도횟수 : 1회
*/



#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567891
#define pii pair<int, int>

using namespace std;

void dijkstra(vector<vector<pii>>& graph, int start, int end, int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, v1, v2, cost, start, end;
    cin >> n >> m;

    vector<vector<pii>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        graph[v1].push_back({v2, cost});
    }
    cin >> start >> end;

    dijkstra(graph, start, end, n);

    return 0;
}


void dijkstra(vector<vector<pii>>& graph, int start, int end, int num)
{
    priority_queue<pii> pq;


    vector<int> dist(num + 1, INF);
    vector<bool> visited(num + 1);
    
    pq.push({0, start});
    dist[start] = 0;

    int vertex;
    while(!pq.empty())
    {   
        vertex = pq.top().second;
        pq.pop();

        if (visited[vertex]) continue;
        visited[vertex] = true;

        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (dist[graph[vertex][i].first] > dist[vertex] + graph[vertex][i].second)
            {
                dist[graph[vertex][i].first] = dist[vertex] + graph[vertex][i].second;
                pq.push({-dist[graph[vertex][i].first], graph[vertex][i].first});
            }
        }
    }

    cout << dist[end];
}