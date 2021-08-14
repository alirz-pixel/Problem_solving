/*
백준 1260번 DFS와 BFS || 실버2
https://www.acmicpc.net/problem/1260






시작시간 12:10
종료시간 12:40
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& graph, int start, int num);
void BFS(vector<vector<int>>& graph, int start, int num);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, v, v1, v2;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(graph, v, n);

    cout << "\n";
    BFS(graph, v, n);

    return 0;
}


void DFS(vector<vector<int>>& graph, int start, int num)
{
    vector<bool> v(num + 1);
    stack<int> st;

    v[start] = true;
    st.push(start);
    cout << start << " ";

    int top;
    while(!st.empty())
    {
        int top = st.top();
        int i;

        for (i = 0; i < graph[top].size(); i++)
            if (!v[graph[top][i]])
            {
                st.push(graph[top][i]);
                v[graph[top][i]] = true;
                cout << graph[top][i] << " ";

                break;
            }

        if (i == graph[top].size())
            st.pop();
    }
}


void BFS(vector<vector<int>>& graph, int start, int num)
{
    vector<bool> v(num + 1);
    queue<int> q;

    q.push(start);
    v[start] = true;

    int front;
    while(!q.empty())
    {
        front = q.front();
        cout << front << " ";
        q.pop();

        for (int i = 0; i < graph[front].size(); i++)
            if (!v[graph[front][i]])
            {
                q.push(graph[front][i]);
                v[graph[front][i]] = true;
            }
    }
}       