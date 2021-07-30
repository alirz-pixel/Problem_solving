/*
백준 11779 최소비용 구하기 2 || 골드 3
https://www.acmicpc.net/problem/11779



분류가 다익스트라임을 아는 상태에서 풀기 시작하였기 때문에
풀이 시간은 얼마 안 걸릴 것이라 예상한다.

허나 경로를 출력해야하기 때문에 이전에 풀었던 다익스트라 문제 보다는 좀 걸릴 것이라 생각한다.

같이 PS 스터디를 해주시는 형님께서 pre라는 변수를 따로 두어 
경로를 출력하면 쉽다고 하여, dist가 갱신 될 떄마다
dist로 오게된 경로의 정점을 넣어주어 마지막에 출력했더니
쉽게 맞출 수 있었다.

시작 시간 : 11:26
종료 시간 : 11:55    총 걸린 시간 : 29분  || 시도 횟수 1번
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 987654321

using namespace std;

void dijkstra(vector<vector<int>>& graph, int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, v1, v2, cost;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        if (graph[v1][v2] < cost)
            continue;

        graph[v1][v2] = cost;
    }

    dijkstra(graph, n);
    return 0;
}


void dijkstra(vector<vector<int>>& graph, int num)
{
    int start, end;
    cin >> start >> end;


    vector<int> dist(num + 1, INF);
    vector<int> pre(num + 1, -1);
    vector<bool> visited(num + 1, false);

    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

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

                pre[i] = vertex;
            }
        }
    }


    stack<int> st;
    int i = end;
    st.push(end);
    while (pre[i] != -1)
    {
        st.push(pre[i]);
        i = pre[i];
    }

    cout << dist[end] << "\n";
    cout << st.size() << "\n";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}