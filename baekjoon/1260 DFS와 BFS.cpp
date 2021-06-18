#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& graph, int startV, int maxVertex);
void bfs(vector<vector<int>>& graph, int startV, int maxVertex);

int main(void)
{
    int v1, v2;
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(graph, V, N + 1);
    bfs(graph, V, N + 1);
}

void dfs(vector<vector<int>>& graph, int startV, int maxVertex)
{
    int top = 0;

    vector<bool> visited(maxVertex);
    stack<int> s;
    s.push(startV);

    while (!s.empty())
    {
        top = s.top();
        s.pop();

        if (visited[top]) continue;

        cout << top << " ";
        visited[top] = true;

        sort(graph[top].begin(), graph[top].end(), greater<int>());
        for (int i = 0; i < graph[top].size(); i++)
            if (!visited[graph[top][i]]) s.push(graph[top][i]);
    }
    cout << "\n";
}

void bfs(vector<vector<int>>& graph, int startV, int maxVertex)
{
    int front = 0;

    vector<bool> visited(maxVertex);
    queue<int> q;
    q.push(startV);

    while (!q.empty())
    {
        front = q.front();
        q.pop();

        if (visited[front]) continue;

        cout << front << " ";
        visited[front] = true;

        sort(graph[front].begin(), graph[front].end());
        for (int i = 0; i < graph[front].size(); i++)
            if (!visited[graph[front][i]]) q.push(graph[front][i]);
    }
}