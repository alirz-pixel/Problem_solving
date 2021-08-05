/*
백준 14501 퇴사 || 골드5
https://www.acmicpc.net/problem/14501







시작 시간 7:06
종료 시간 7:32
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    int next, end = n;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        dp[i+1] = max(dp[i+1], dp[i]);

        next = arr[i].first + i;
        if (next > n)
        {
            dp[end] = max(dp[i], dp[end]);
            continue;
        }

        dp[next] = max(arr[i].second + dp[i], dp[next]);
    }

    cout << dp[end];
    return 0;
}