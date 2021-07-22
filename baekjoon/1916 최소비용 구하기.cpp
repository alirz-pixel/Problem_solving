/*
백준 1916 최소비용 구하기 || 골드 5
https://www.acmicpc.net/problem/1916



방향이 없는 그래프인지, 방향 그래프인지 확인을 제대로 안하고
문제부터 풀어서 오래 걸렸다...

알고리즘 자체도 처음 배우는거라 인터넷을 참고하여 풀었음..

시작 시간 : 7:41
종료 시간 : 8:58
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567891

using namespace std;

void Dijkstra(vector<vector<int>>& graph, int start, int end, int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, v1, v2, cost, start, end;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        if (graph[v1][v2] < cost)
            continue;

        graph[v1][v2] = cost;
    }
    cin >> start >> end;

    Dijkstra(graph, start, end, n);

    return 0;
}


void Dijkstra(vector<vector<int>>& graph, int start, int end, int num)
{
    priority_queue<pair<int, int>> pq;

    vector<int> dist(num + 1, INF);
    vector<bool> visited(num + 1);

    pq.push({0, start});
    dist[start] = 0;


    int vertex, cost;
    while (!pq.empty())
    {
        cost = -pq.top().first;
        vertex = pq.top().second;
        pq.pop();

        if (visited[vertex]) continue;
        visited[vertex] = true;

        for (int i = 1; i <= num; i++) 
        {
            if (dist[i] > cost + graph[vertex][i])
            {
                dist[i] = cost + graph[vertex][i];
                pq.push({-dist[i], i});
            }
        }
    }

    cout << dist[end];
}