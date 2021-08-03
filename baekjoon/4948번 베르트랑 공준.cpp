/*
백준 4948 베르트랑 공준 || 실버2
https://www.acmicpc.net/problem/4948


시작 시간 2:21
종료 시간 2:36
*/

#include <iostream>
#include <vector>
#define MAX 123456

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    vector<bool> dp((2 * MAX) + 1, false); // 
    dp[0] = dp[1] = true;
    for (int i = 2; i * i <= 2 * MAX; i++)
    {
        if (dp[i] == true) continue;

        for (int j = 2 * i; j <= 2 * MAX; j += i)
            dp[j] = true;
    }

    
    int n, cnt;
    while(1)
    {
        cnt = 0;

        cin >> n;
        if (n == 0)  break;

        for (int i = n + 1; i <= 2*n; i++)
            if (dp[i] == false)
                cnt++;

        cout << cnt << "\n";
    };
    

    return 0;
}