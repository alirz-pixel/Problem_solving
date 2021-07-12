/*
백준 11724 || 실버 2
https://www.acmicpc.net/problem/11724


단순한 그래프 문제 (DFS나 BFS) 였기 때문에
간단하게 15분 만에 풀 수 있었던 것 같다.

시작시간 : 2:40
종료시간 : 2:55
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<bool>& visited, vector<vector<int>>& graph, int start);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, v1, v2, cnt = 0;
    cin >> n >> m;

    vector<bool> visited(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }


    for(int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            BFS(visited, graph, i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}


void BFS(vector<bool>& visited, vector<vector<int>>& graph, int start)
{
    vector<int> top;
    queue<vector<int>> q;

    visited[start] = true;
    q.push(graph[start]);
    while(!q.empty())
    {
        top = q.front();   q.pop();

        for (int i = 0; i < top.size(); i++)
            if (visited[top[i]] == false)
            {
                visited[top[i]] = true;
                q.push(graph[top[i]]);
            }
    }
}