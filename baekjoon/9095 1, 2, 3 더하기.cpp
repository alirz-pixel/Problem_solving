/*
백준 9095번 1, 2, 3 더하기 || 실버 3
https://www.acmicpc.net/problem/9095

이 문제를 수식화 하려 했으나 도저히 모르겠어서
다른 사람의 답을 보게되었다...

문제의 방법은 수식화가 아닌 재귀의 방식을 이용한 것이다.
그냥 단순히 입력이 n이 주어지면 이 n이 나올 때까지 재귀를 돌면서 +1, +2, +3를 반복하면 되는 것이다.

==> 이렇게 코드를 짜고나니 f(n) = f(n - 1) + f(n - 2) + f(n - 3);이 되는것을 확인하였다.
==> 즉, 계산실수를 하여 수식화를 못한거였음..
*/

#include <iostream>

using namespace std;

void loop(int aim, int now);

int cnt;
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int DP[12] { 0, };
    int T, n;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;

        if (DP[n] == 0)
        {
            cnt = 0;
            loop(n, 0);

            DP[n] = cnt;
        }

        cout << DP[n] << "\n";
    }
    return 0;
}

void loop(int aim, int now)
{
    if (aim < now)
        return;

    if (aim == now)
    {
        cnt++;
        return;
    }

    
    loop(aim, now + 1);
    loop(aim, now + 2);
    loop(aim, now + 3);

    return;
}