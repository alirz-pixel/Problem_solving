#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
void DFS(vector<vector<int>>& graph, int now);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, v1, v2;
    cin >> n;

    visited = vector<bool>(n + 1, false);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(graph, 1);

    return 0;
}


void DFS(vector<vector<int>>& graph, int now)
{
    cout << now << " ";
    visited[now] = true;

    for (int i = 0; i < graph[now].size(); i++)
        if (visited[graph[now][i]] == false)
        {
            DFS(graph, graph[now][i]);
            cout << now << " ";
        }

}