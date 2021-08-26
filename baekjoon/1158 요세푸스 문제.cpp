/*  2021-08-26  8:1:46
백준 1158번 요세푸스 문제 || 실버5
https://www.acmicpc.net/problem/1158




시작시간 : 1:46
종료시간 : 1:50       걸린시간 : 4분  ||  제출횟수 : 1회
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
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);


    // solve();
    cout << "<";
    int front, cnt;
    while(1)
    {
        cnt = k-1;

        while (cnt--)
        {
            q.push(q.front());
            q.pop();
        }

        if (q.size() == 1)
            break;

        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">";

    return 0;
}