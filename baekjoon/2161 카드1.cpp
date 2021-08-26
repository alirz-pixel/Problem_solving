/*  2021-08-22  8:36
백준 2161번 카드1 || 브론즈2
https://www.acmicpc.net/problem/2161






시작시간 : 1:30
종료시간 : 1:33       걸린시간 : 3분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    queue<int> q;
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);

    
    // solve();
    bool turn = false;
    while(!q.empty())
    {
        // 버리는 차례
        if (!turn)
            cout << q.front() << " ";

        // 카드를 제일 아래로 내리는 차례
        else
            q.push(q.front());

        turn = !turn;
        q.pop();
    }


    return 0;
}
