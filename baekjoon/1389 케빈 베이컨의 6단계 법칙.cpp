/*
백준 1389번 케빈 베이컨의 6단계 법칙 || 실버 1
https://www.acmicpc.net/problem/1389


입력에 대해 방향없는 그래프를 만든 후, 
모든 점들에 대해 lever order(큐 이용)을 하되 큐를 돈 횟수를 cnt에 각각 더해주면 
문제에서 원하는 답이 나올 것이다.

그래프는 인접리스트로 만들 것임.
주의) 친구 관계가 중복되어서 들어올 수 있으므로, 방문처리를 해줘야 한다.


시작시간 : 5:39
종료시간 : 6:18,   시도횟수 1번  ||  소요시간 40분
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int levelorder(vector<vector<int>>& graph, int N, int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    
    int min = 1234567891, min_Index = 101, temp;
    int N, M, V1, V2;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0)); //중복 친구 관계를 처리하기 위한 방문처리 (2차원 배열)

    for (int i = 0; i < M; i++)
    {
        cin >> V1 >> V2;

        if (!visited[V1][V2])
        {    
            graph[V1].push_back(V2);
            graph[V2].push_back(V1);

            visited[V1][V2] = true;
            visited[V2][V1] = true;
        }
    }


    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    for (int i = 1; i <= N; i++)
    {
        temp = levelorder(graph, N, i);

        if (min > temp)
        {
            min = temp;
            min_Index = i;
        }
    }
        
    cout << min_Index;
    return 0;
}

int levelorder(vector<vector<int>>& graph, int N, int start)
{
    int cnt = 1, result = 0, size;
    vector<bool> visited(N + 1);
    queue<vector<int>> q;

    q.push(graph[start]);
    visited[start] = true;
    while (!q.empty())
    {
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            for(auto i : q.front())
                if (!visited[i])
                {
                    q.push(graph[i]);
                    visited[i] = true;
                    result += cnt;
                }

            q.pop();
        }

        cnt++;
    }

    return result;
}

/*
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
            cout << i << " " << graph[i][j] << "\n";
        cout << "\n";
    }
*/