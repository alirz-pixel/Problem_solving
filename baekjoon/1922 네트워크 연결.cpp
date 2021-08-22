/*  2021-08-22  8:36
백준 1922번 네트워크 연결 || 골드4
https://www.acmicpc.net/problem/1922



최소 스패닝 트리 (크루스칼 알고리즘)을 학습한 후로부터
16분이 걸렸다.

시작시간 : 7:27
종료시간 : 7:43      걸린시간 : 16분  ||  제출횟수 : 1회
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find(vector<int>& parent, int x);
bool union_(vector<int>& parent, int a, int b);
void solve(vector<pair<int, pair<int, int>>>& edge, vector<int>& parent, int n, int m);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, v1, v2, cost;
    cin >> n >> m;


    // 유니온 파인드에서의 루트를 설정
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    // 입력받기
    vector<pair<int, pair<int, int>>> edge(m);
    int top = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> cost;

        edge[top++] = {cost, {v1, v2}};
    }

    sort(edge.begin(), edge.end());
    solve(edge, parent, n, m);


    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent, parent[x]);
    return parent[x];
}

bool union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return false;

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;

    return true;
}


void solve(vector<pair<int, pair<int, int>>>& edge, vector<int>& parent, int n, int m)
{
    int cost, result = 0;
    pair<int, int> vertex;
    for (int top = 0; top < m; top++)
    {
        cost = edge[top].first;
        vertex = edge[top].second;

        // 사이클이 형성되지 않는다면
        if (union_(parent, vertex.first, vertex.second))
            result += cost;
    }

    cout << result;
}