/*
백준 11404 플로이드 || 골드 4
https://www.acmicpc.net/problem/11404



최단 거리의 문제는 방향성이 있는 그래프인지부터 확인할 것
 --> 방향성이 있는 그래프임


시작 시간 : 5:24
종료 시간 : ???
*/



#include <iostream>
#include <vector>

using namespace std;

void length(vector<vector<int>> graph, int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    
    int n, m, v1, v2, cost;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        if (graph[v1][v2] != 0 && graph[v1][v2] < cost)
            continue;

        graph[v1][v2] = cost;
    }

    length(graph, n);

    return 0;
}


void length(vector<vector<int>> graph, int num)
{
    for (int mid = 1; mid <= num; mid++)
        for (int i = 1; i <= num; i++)
        {
            if (mid == i) continue;

            for (int j = 1; j <= num; j++)
            {
                if (i == j) continue;

                if (graph[i][mid] && graph[mid][j])
                {
                    if (graph[i][j] == 0)
                        graph[i][j] = graph[i][mid] + graph[mid][j];

                    else if (graph[i][j] > graph[i][mid] + graph[mid][j])
                        graph[i][j] = graph[i][mid] +graph[mid][j];
                }
            }
        }

    
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
            cout << graph[i][j] << " ";

        cout << "\n";
    }
}