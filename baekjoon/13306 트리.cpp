/*  2021-08-22  8:36
백준 13306번 트리 || 플레1
https://www.acmicpc.net/problem/13306




충북대학교 알고리즘 특강 시간에 이 문제를 푸는 알고리즘에 대해 설명을 해주셔서
어렵지 않게 짰던 것 같다.

알아낸 점 : 
  무조건 'input의 순서 = 연산의 순서'라고 생각하지말고
  input의 순서를 뒤집어서 연산을 하고, 결과의 순서를 다시 바꿔서 푸는 방법도 있다는 것을 알게되었다.
  (알고리즘 분류 : 오프라인 쿼리)


시작시간 : 7:40 
종료시간 : 8:00     걸린시간 : 대략 20분  ||  제출횟수 : 1회
*/




#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int find(vector<int>& parent, int x);
bool union_(vector<int>& parent, int a, int b);
void solve(vector<int>& graph, stack<pair<int, pair<int, int>>>& st, int n, int q);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, q, command, v1, v2;
    cin >> n >> q;

    // n - input();
    vector<int> graph(n+1);
    graph[1] = 1;
    for (int i = 2; i <= n; i++)
        cin >> graph[i];        


    // q - input();
    stack<pair<int, pair<int, int>>> st;
    for (int i = 0; i < (n-1)+q; i++)
    {
        cin >> command;

        // 제거 연산
        if  (command == 0)
        {
            cin >> v1;
            st.push( {command, { v1, -1 }} );
        }

        // 질의 연산
        else if (command == 1)
        {
            cin >> v1 >> v2;
            st.push( {command, { v1, v2 }} );
        }
    }

    solve(graph, st, n, q);

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
        return true;

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
    
    return false;
}

void solve(vector<int>& graph, stack<pair<int, pair<int, int>>>& st, int n, int q)
{
    stack<bool> result;

    // 유니온 파인드 init()
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int command;
    pair<int, int> vertex;
    while(!st.empty())
    {
        command = st.top().first;
        vertex = st.top().second;
        st.pop();

        // 질의 연산
        if (command == 1)
        {
            if (find(parent, vertex.first) == find(parent, vertex.second))
                result.push(true);
            else
                result.push(false);
        }

        // 연결 연산
        else
        {
            parent[vertex.first] = graph[vertex.first];
            find(parent, vertex.first);
        }
    }

    while(!result.empty())
    {
        if(result.top())
            cout << "YES\n";
        else
            cout << "NO\n";

        result.pop();
    }
}