/*  2021-08-18  3:15
백준 9184번 신나는 함수 실행 || 실버2
https://www.acmicpc.net/problem/9184



피보나치 함수를 구현할 때처럼 재귀함수를 DP를 이용해 풀었다.


시작시간 3:16
종료시간 3:32       걸린시간 : 16분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;


// vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21)));
int dp[21][21][21];
int solve(int a, int b, int c);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);
    

    int a, b, c;


    while (1) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }
    


    return 0;
}


int solve(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);


    int& ret = dp[a][b][c];
    if (ret != 0)
        return ret;

    if (a < b && b < c)
        ret = (solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c));
    else
        ret = (solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1));

    return ret;
}