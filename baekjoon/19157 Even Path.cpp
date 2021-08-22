/*  2021-08-22  8:36
백준 19157번 Even Path || 골드4
https://www.acmicpc.net/problem/19157


인터넷을 참고하여 풀음.
참고하기 전까진 그래프이론으로 풀어야 되는 줄 알았으나 시간초과 3연타 맞음

시작시간 : ?:??
종료시간 : ?:??    (의미없음.) 
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;

    vector<int> col(n+1), row(n+1), R(n+1), C(n+1);
    for (int i = 1; i <= n; i++)
        cin >> row[i];

    for (int i = 1; i <= n; i++)
        cin >> col[i];


    R[1] = C[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (row[i]%2 == row[i-1]%2)
            R[i] = R[i-1];
        else
            R[i] = i;

        if (col[i]%2 == col[i-1]%2)
            C[i] = C[i-1];
        else
            C[i] = i;
    }


    // solve();
    int ra, ca, rb, cb;
    while(q--)
    {
        cin >> ra >> ca >> rb >> cb;

        if (ra < rb) swap(ra, rb);
        if (ca < cb) swap(ca, cb);

        if (R[ra] <= rb && C[ca] <= cb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}