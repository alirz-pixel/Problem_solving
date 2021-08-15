/*
백준 11725번 트리의 부모 찾기 || 실버2
https://www.acmicpc.net/problem/11725



유니온 파인드로 풀어보려 했으나,
로직이 떠오르지 않아 BFS로 탐색하며

부모를 갱신하며 풀었다.
(인터넷 검색을 해보니, 유니온 파인드로 푼 사람은 없었음..)

시작시간 8:36
종료시간 8:43   걸린시간 : 13분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& graph, int num);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, v1, v2;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    BFS(graph, n);

    return 0;
}


void BFS(vector<vector<int>>& graph, int num)
{
    vector<int> parent(num + 1);
    vector<bool> v(num + 1);
    queue<int> q;

    q.push(1);
    v[1] = true;

    int front;
    while(!q.empty())
    {
        front = q.front();
        q.pop();


        for (auto i : graph[front])
            if (!v[i])
            {
                q.push(i);
                v[i] = true;

                parent[i] = front;
            }
    }

    for(int i = 2; i <= num; i++)
        cout << parent[i] << "\n";
}