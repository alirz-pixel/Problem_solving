/*  2021-08-17
백준 12852번 1로 만들기 2 || 실버1
https://www.acmicpc.net/problem/12852



1로 만들기 1을 풀었기 때문에
BFS라는 것을 바로 알 수 있었으며

DP특강을 들은 후에 푼 문제라
역추적을 쉽게 활용할 수 있었음.

시작시간 9:58
종료시간 10:17       걸린시간 : 19분  ||  제출횟수 : 1회
*/




#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    solve(n);

    return 0;
}


void solve(int n)
{
    vector<int> dp(n + 1, -1);

    queue<int> q;
    q.push(n);

    int front;
    while(!q.empty())
    {
        front = q.front();
        q.pop();


        if (front % 3 == 0 && dp[front/3] == -1)
        {
            dp[front/3] = front;

            if (front / 3 == 1)
                break;

            q.push(front/3);
        }

        if (front % 2 == 0 && dp[front/2] == -1)
        {
            dp[front/2] = front;

            if (front / 2 == 1)
                break;

            q.push(front/2);
        }

        if (front > 1 && dp[front-1] == -1)
        {
            dp[front-1] = front;

            if (front-1 == 1)
                break;

            q.push(front-1);
        }
    }


    stack<int> result;
    int searchBack = 1;
    while(dp[searchBack] != -1)
    {
        result.push(searchBack);
        searchBack = dp[searchBack];
    }
    result.push(n);

    cout << result.size()-1 << "\n";
    while(!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
}