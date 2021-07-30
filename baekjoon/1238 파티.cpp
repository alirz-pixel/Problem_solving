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


시작 시간 : 4:30
종료 시간 : 4:52       총 걸린시간 : 22분  ||  시도횟수 2회
*/


#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

void length(vector<vector<int>> graph, int num, int party);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, x, v1, v2, cost;
    cin >> n >> m >> x;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        if (graph[v1][v2] < cost) continue;

        graph[v1][v2] = cost;
    }

    length(graph, n, x);

    return 0;
}


void length(vector<vector<int>> graph, int num, int party)
{
    for (int mid = 1; mid <= num; mid++)
        for (int i = 1; i <= num; i++)
        {
            if (mid == i) continue;
            if (graph[i][mid] >= INF) continue;

            for (int j = 1; j <= num; j++)
            {
                if (i == j) continue;

                if (graph[i][j] > graph[i][mid] + graph[mid][j])
                    graph[i][j] = graph[i][mid] + graph[mid][j];
            }
        }

    int max = 0, result;
    for (int i = 1; i <= num; i++)
    {
        if (i == party) continue;

        result = graph[i][party] + graph[party][i];

        if (max < result)
            max = result;
    }

    cout << max;
}