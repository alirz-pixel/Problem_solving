/*
백준 7576번 토마토  ||  실버 1
https://www.acmicpc.net/problem/7576

중간에 쉬긴 했지만 대략 30분 정도 걸린 것 같음
DFS와 BFS 문제를 푼 후에 이 문제를 풀었기 때문에 기본적인 로직은 작성하기 쉬웠으며,
대략 한 달 전에 이 문제를 보고 고민했었기 때문에 30분 정도만 걸린 것 같음
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int day = 0, cnt = 0;

void bfs(vector<vector<int>>& tomato, int maxX, int maxY);

int main(void)
{
    int M, N;
    cin >> M >> N;

    vector<vector<int>> tomato(N); 
    for (int y = 0; y < N; y++)
    {
        vector<int> temp(M);
        tomato[y] = temp;

        for (int x = 0; x < M; x++)
        {
            cin >> tomato[y][x];

            if (tomato[y][x] == 1)
            {
                cnt++;
                q.push({x, y});
            }
        }
    }

    bfs(tomato, M, N);


    bool result = true;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (tomato[y][x] == 0)
                result = false;

    if (result)
        cout << day;

    else
        cout << "-1";
}

void bfs(vector<vector<int>>& tomato, int maxX, int maxY)
{
    int cnt_temp = 0;

    int y = 0, x = 0;
    int my[4] = { 1, -1, 0, 0 };
    int mx[4] = { 0, 0, -1, 1 };

    while (!q.empty())
    {
        if (cnt == 0)
        {
            cnt = cnt_temp;
            cnt_temp = 0;
            day++;
        }

        for (int i = 0; i < 4; i++)
        {
            x = q.front().first + mx[i];
            y = q.front().second + my[i];

            if (x < 0 || y < 0 || x >= maxX || y >= maxY) continue;

            if (tomato[y][x] == 0)
            {
                q.push({x, y});
                tomato[y][x] = 1;
                cnt_temp++;
            }
        }

        q.pop();
        cnt--;
    }
}