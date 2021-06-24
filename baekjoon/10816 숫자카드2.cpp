/*
백준 10816번 숫자 카드 2  || 실버 4
https://www.acmicpc.net/problem/10816

시작 시간 : 5:15
종료 시간 : 5:21
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    vector<int> cnt(20000002);

    int N, M, temp;
    cin >> N;   

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        cnt[temp + 10000000]++;
    }


    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        cout << cnt[temp + 10000000] << " ";
    }

    return 0;
}