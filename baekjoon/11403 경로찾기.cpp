/*
백준 11403번 경로 찾기 || 실버 1
https://www.acmicpc.net/problem/11403


입력 자체가 인접행렬로 주어지기 때문에 
크기가 N인 2차원 bool형 배열을 만들어 거기다가 값을 저장한다.

while 문을 통해 연결 되어있는 길을 찾을 예정이며,
종료조건은 : false가 나왔을 떄 이다.

결과값은 N * N 짜리의 2차원 bool형 배열을 만들어야 할 듯 싶다.


시작시간 : 7:11
종료시간 : 
*/



#include <iostream>
#include <vector>

using namespace std;

void findPath(vector<vector<int>>& graph, int end);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    

    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    
    findPath(graph, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << " ";

        cout << "\n";
    }
    return 0;
}


void findPath(vector<vector<int>>& graph, int end)
{
    for (int mid = 0; mid < end; mid++)
        for (int i = 0; i < end; i++)
            for (int j = 0; j < end; j++)
                if (graph[i][mid] && graph[mid][j])
                    graph[i][j] = 1;
}