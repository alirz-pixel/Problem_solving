/*
백준 1976번 여행 가자 || 골드4
https://www.acmicpc.net/problem/1976



유니온 파인드 알고리즘을 이용한 문제를 찾아서 풀었기 때문에
그렇게 어려움 없이 문제를 풀 수 있었던 것 같다.

만약에 이 문제에 대한 알고리즘 분류를 보지 않고 문제를 풀었다면,
그래프 알고리즘으로 풀었을 가능성이 커보인다.


시작시간 9:21
종료시간 9:36    걸린시간 : 15분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> rank_;

int find(vector<int>& parent, int x);
void union_(vector<int>& parent, int a, int b);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, temp;
    cin >> n >> m;

    vector<int> parent(n + 1);
    rank_ = vector<int>(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;

            if (temp)
                union_(parent, i, j);
        }

    bool result = true;
    int same;

    cin >> temp;
    same = find(parent, temp);
    for (int i = 2; i <= m; i++)
    {
        cin >> temp;

        if (same != find(parent, temp))
            result = false;
    }

    if (result)
        cout << "YES";
    else 
        cout << "NO";


    return 0;
}


int find(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return;

    if (rank_[x] < rank_[y])
    {
        parent[x] = y;
        rank_[y] += rank_[x];
    }
    else
    {
        parent[y] = x;
        rank_[x] += rank_[y];
    }
}