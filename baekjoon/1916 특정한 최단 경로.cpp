/*
백준 1916 특정한 최단 경로 || 골드 4
https://www.acmicpc.net/problem/1504



1916번 최소비용 구하기 문제를 풀고난 후, 
바로 다음 문제로 이 문제를 풀게되었다.

문제 풀기 전 다짐.  그래프의 방향성 확인하기 (이번 문제는 방향이 없는 그래프임)


1번 틀려서 다음날에 다시 코드적음

시작시간 : 8:45
종료시간 : 9:02    총 시도횟수 : 2번  ||  걸린시간 : 17분 + (전날에 한 시간 30분?)
*/



#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 123456789

using namespace std;

int Dijkstra(vector<vector<int>> graph, int start, int end, int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, e, v1, v2, cost, tempV1, tempV2;
    long long int resultMin = 0, result;
    cin >> n >> e;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2 >> cost;

        if (graph[v1][v2] < cost)
            continue;

        graph[v1][v2] = cost;
        graph[v2][v1] = cost;
    }
    cin >> tempV1 >> tempV2;

    result = Dijkstra(graph, 1, tempV1, n);
    result += Dijkstra(graph, tempV1, tempV2, n);
    result += Dijkstra(graph, tempV2, n, n);
    
    resultMin = Dijkstra(graph, 1, tempV2, n);
    resultMin += Dijkstra(graph, tempV2, tempV1, n);
    resultMin += Dijkstra(graph, tempV1, n, n);


    resultMin = min(result, resultMin);

    if (resultMin >= INF)
        cout << "-1";
    else
        cout << resultMin;
    return 0;
}


int Dijkstra(vector<vector<int>> graph, int start, int end, int num)
{
    priority_queue<pair<int, int>> pq;


    vector<int> dist(num + 1, INF);
    vector<bool> visited(num + 1);

    dist[start] = 0;
    pq.push({dist[start], start});

    int vertex;
    while(!pq.empty())
    {
        vertex = pq.top().second;
        pq.pop();

        if (visited[vertex]) continue;
        visited[vertex] = true;

        for (int i = 1; i <= num; i++)
        {
            if (dist[i] > dist[vertex] + graph[vertex][i])
            {
                dist[i] = dist[vertex] + graph[vertex][i];
                pq.push({-dist[i], i});
            }
        }
    }

    return dist[end];
}