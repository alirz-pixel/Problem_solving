/*
백준 2667번 단지번호붙이기 || 실버 1
https://www.acmicpc.net/problem/2667


단지 탐색은 2차원 배열을 선언하여 BFS를 이용하면 될 듯,
배열에서 1인 값들은 탐색이 끝난 후, 0으로 바꿔주면 될 듯

결과값 즉, 단지 내 집의 수는 우선순위 큐를 이용하면 될 듯 싶다.
(= 혹은 sort해도 괜찮음)


시작시간 : 8:33
종료시간 : 3:48
*/



#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define MAX 25

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

string graph[MAX];
queue<pair<int, int>> Q_index;
priority_queue<int, vector<int>, greater<int>> PQ;


void BFS(int x, int y, int& end, int& count);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, count, result = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> graph[i];

        for (int j = 0; j < N; j++)
            if (graph[i][j] == '1')
            {
                Q_index.push({i, j});
            }
    }

    while(!Q_index.empty())
    {
        int y = Q_index.front().first;
        int x = Q_index.front().second;

        if (graph[y][x] == '1')
        {
            count = 0;
            result++;
            BFS(x, y, N, count);
            PQ.push(count);
        }

        
        Q_index.pop();
    }

    cout << result << "\n";
    while(!PQ.empty())
    {
        cout << PQ.top() << "\n";
        PQ.pop();
    }
    return 0;
}


void BFS(int x, int y, int& end, int& count)
{
    if (x < 0 || y < 0 || x >= end || y >= end)
        return;

    count++;
    graph[y][x] = '0';
    for (int i = 0; i < 4; i++)
    {
        int my = y + dy[i];
        int mx = x + dx[i];

        if (mx >= 0 && my >= 0 && mx < end && my < end)
            if(graph[my][mx] == '1')
                BFS(mx, my, end, count);
    }

    return;
}