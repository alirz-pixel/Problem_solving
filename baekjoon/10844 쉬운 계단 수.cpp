/*  2021-08-31  4:58
백준 10844번 쉬운 계단 수  ||  실버1
https://www.acmicpc.net/problem/10844



다이나믹 프로그래밍의 top-down 방식을 이용하여 풀었다.

로직 설명 :
 - 맨 앞자리는 0~9가 올 수 있으므로 for문을 돌리며 topdown 함수를 호출한다.
   그리고 모든 수에 대해서 (level-1, nowNum-1) + (level-1, nowNum+1)을 하여 작은 문제로 나눈다.

    여기서 이미 계산한 것을 또 계산하는 경우가 생길 수 있으므로
    dp[level][num] 변수를 만들어 이런 경우를 방지하였다.


   

시작시간 : ?:??
종료시간 : ?:??       걸린시간 : ??분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <vector>
const long long mod = 1000000000;

using namespace std;
using ll = long long;

ll topdown(vector<vector<ll>>& dp, int level, int num);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    // dp[level][num];
    // num = 0~9;
    vector<vector<ll>> dp(n, vector<ll>(10, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[0][i] = 1;

    ll result = 0, temp;
    for (int i = 0; i <= 9; i++)
        result = (result + topdown(dp, n-1, i)) % mod;

    cout << result;

    return 0;
}


ll topdown(vector<vector<ll>>& dp, int level, int num)
{
    if (num < 0 || num > 9)
        return 0;

    if (level == 0 && num == 0)
        return 0; // dp[0][0];

    if (dp[level][num])
        return dp[level][num];

    return dp[level][num] = (topdown(dp, level-1, num+1) + topdown(dp, level-1, num-1)) % mod;
}