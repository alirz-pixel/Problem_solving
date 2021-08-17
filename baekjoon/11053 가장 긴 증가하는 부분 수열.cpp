/*  2021-08-17
백준 11053번 가장 긴 증가하는 부분 수열 || 실버2
https://www.acmicpc.net/problem/11053



가장 긴 증가하는 부분 수열을 O(n^2)으로 간단하게 구현할 수 있다.
다만, 입력이 10,000이 되는 순간 O(log n)으로 풀어야 되는 것이 주의점이다.

시작시간 10:34
종료시간 10:42
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

    vector<int> a(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[j]+1, dp[i]);

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}