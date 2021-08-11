/*
백준 2606 바이러스 || 실버3
https://www.acmicpc.net/problem/2606


저번 풀이에선 이 문제를 그래프 이론 (BFS)를 이용하여 풀었었다.
이번엔 유니온 파인드를 학습하게 되어, 이것을 사용하여 풀었는데

유니온 파인드를 학습할 때,
유니온 부분에서 '그래프의 깊이가 낮은 것이 -> 그래프의 깊이가 높은 것쪽으로 붙게' 만들라는 이야기가 있어서
이렇게 구현해서 제출했으나, 이 문제는
1이랑 연결된 노드의 루트노드가 1이 나와야하기 때문에
뒤늦게 유니온의 합치는 과정을 조금 수정하여 제출하였다.


시작시간 8:15
종료시간 8:34         걸린시간 : 19분  ||  시도횟수 : 3회
*/



#include <iostream>
#include <vector>

using namespace std;


int find(vector<int>& parent, int a);
void union_(vector<int>& parent, int a, int b);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, v1, v2, cnt = 0;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;

        union_(parent, v1, v2);
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (find(parent, i) == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}


int find(vector<int>& parent, int a)
{
    if (parent[a] == a)
        return a;

    parent[a] = find(parent, parent[a]);
    return parent[a];
}

void union_(vector<int>& parent, int a, int b)
{
    int x = find(parent, a);
    int y = find(parent, b);

    if (x == y)
        return;

    if (x > y)
        parent[x] = y;
    else   
        parent[y] = x;
    // if (rank_[x] >= rank_[y])
    // {
    //     parent[y] = x;
    //     rank_[x] += rank_[y];
    // }
    // else
    // {
    //     parent[x] = y;
    //     rank_[y] += rank_[x];
    // }
}