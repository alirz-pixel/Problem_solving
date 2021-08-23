/*  2021-08-22  8:36
백준 2887번 행성 터널 || 골드1
https://www.acmicpc.net/problem/2887



(유니온 파인드 및 최소 스패닝 트리[크루스칼])
최소 스패닝 트리를 구할 때, min( [x, y, z] 의 차 )를 이용해야 했으므로
X, Y, Z 의 값들을 따로 저장해두었다가 정렬하여 위의 min 부분을 빠르게 구하였다.

이 이후는 최소 스패닝 트리의 알고리즘을 그대로 사용하였다.



시작시간 : 3:01
종료시간 : 3:39      걸린시간 : 대략 38분  ||  제출횟수 : 1회
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int find(vector<int>& parent, int x);
bool union_(vector<int>& parent, int a, int b);
void solve(vector<pair<long long int, pair<int, int>>>& edge, vector<int>& parent, int n);
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, x, y, z;
    cin >> n;


    //유니온 파인드 구헌
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // 입력받기
    vector<pair<long long int, int>> inputX(n), inputY(n), inputZ(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;

        inputX[i] = { x, i };
        inputY[i] = { y, i };
        inputZ[i] = { z, i };
    }

    sort(inputX.begin(), inputX.end());
    sort(inputY.begin(), inputY.end());
    sort(inputZ.begin(), inputZ.end());


    // 행성 간의 거리가 좁은 것들 구하기
    vector<pair<long long int, pair<int, int>>> edge;
    for (int i = 0; i < n-1; i++)
    {
        edge.push_back({abs(inputX[i].first-inputX[i+1].first), {inputX[i].second, inputX[i+1].second}});
        edge.push_back({abs(inputY[i].first-inputY[i+1].first), {inputY[i].second, inputY[i+1].second}});
        edge.push_back({abs(inputZ[i].first-inputZ[i+1].first), {inputZ[i].second, inputZ[i+1].second}});
    }

    sort(edge.begin(), edge.end());
    solve(edge, parent, n);

    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
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

void solve(vector<pair<long long int, pair<int, int>>>& edge, vector<int>& parent, int n)
{   
    long long int cost, result = 0;
    pair<int, int> vertex;
    for (int top = 0; top < edge.size(); top++)
    {
        cost = edge[top].first;
        vertex = edge[top].second;

        // 사이클이 형성되지 않는다면
        if (union_(parent, vertex.first, vertex.second))
            result += cost;
    }

    cout << result;
}