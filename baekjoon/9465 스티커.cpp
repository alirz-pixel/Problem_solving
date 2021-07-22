/*
백준 9465 스티커 || 실버 2
https://www.acmicpc.net/problem/9465


문제를 본 후에 그림판으로 직접 최대가 되는 경우들을 계산해보니
DP문제로 풀 수 있다는 것을 알게되었다.

그러다보니 빠른 시간내에 풀 수 있었던 것 같다.

시작시간 : 4:50
종료시간 : 5:07  ||  제출횟수 : 1회     총 걸린시간 17분 + 알파
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        vector<vector<int>> input(2, vector<int>(n + 1, 0));

        for (int j = 0; j < 2; j++)
            for (int k = 1; k <= n; k++)
                cin >> input[j][k];


        dp[0][1] = input[0][1];
        dp[1][1] = input[1][1];
        for (int j = 2; j <= n; j++)
        {
            dp[0][j] = max(max(dp[1][j - 1], dp[0][j - 2]), dp[1][j - 2]) + input[0][j];
            dp[1][j] = max(max(dp[0][j - 1], dp[0][j - 2]), dp[1][j - 2]) + input[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }


    return 0;
}