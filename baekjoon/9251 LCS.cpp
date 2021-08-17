/*
백준 9251번 LCS || 골드5
https://www.acmicpc.net/problem/9251



충북대학교 알고리즘 특강 시간에
다이나믹 프로그래밍을 배우며 이 문제에 대한 알고리즘을 설명해주셔서
쉽게 풀 수 있었다.


시작시간 *:**
종료시간 *:**      (의미없음)
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


    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size()+1, 0));
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1])  dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[a.size()][b.size()];

    return 0;
}