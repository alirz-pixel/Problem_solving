/*
백준 1717 집합의 표현 || 골드4
https://www.acmicpc.net/problem/1717




시작시간 7:29
종료시간 7:40
*/



#include <iostream>
#include <vector>

using namespace std;

vector<int> rank_;

int find(vector<int>& parent, int a);
void union_(vector<int>& parent, int a, int b);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, command, a, b;
    cin >> n >> m;

    rank_ = vector<int>(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank_[i] = 1;
    }

    while (m--)
    {
        cin >> command >> a >> b;

        if (!command)
            union_(parent, a, b);

        else
        {
            int y = find(parent, a);
            int x = find(parent, b);

            if (y != x)
                cout << "NO\n";

            else
                cout << "YES\n";
        }
    }
    return 0;
}


int find(vector<int>& parent, int a)
{
    if (parent[a] == a)
        return a;

    int y = find(parent, parent[a]);
    parent[a] = y;
    return y;
}


void union_(vector<int>& parent, int a, int b)
{
    int x, y;

    x = find(parent, a);
    y = find(parent, b);


    if (x == y)
        return;

    if (rank_[x] > rank_[y])
    {
        // 트리의 깊이가 작은 것이 높은 것쪽으로 들어가야 함.
        parent[y] = x;
        rank_[x] += rank_[y];
    }
    else
    {
        parent[x] = y;
        rank_[y] += rank_[x];
    }
}