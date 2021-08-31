/*  2021-08-31  4:58
백준 2193번 이친수  ||  실버3
https://www.acmicpc.net/problem/2193




첫 번째 풀이 :
 - 수의 규칙을 찾아보니 피보나치 수와 연관이 있다는 것을 알게되었다.
   따라서 간단하게 피보나치 수 코드를 짜서 제출하였다.


시작시간 : 4:58
종료시간 : 5:08       걸린시간 : 10분  ||  제출횟수 : 1회


두 번째 풀이 :
       갯수 :  0   1
 n = 1 일 때,  0   1
 n = 2 일 때,  1   0
 n = 3 일 때,  1   1

 - 이렇게 적어나가다 보니
   현재 n의 0 갯수는 'n-1'의 0의 갯수 + 'n-1'의 1의 갯수이며,
   현재 n의 1 갯수는 'n-1'의 0의 갯수라는 것을 알게되었다.

   이를 이용하여 코드를 짜게 되었다.

시작시간 : ?:??
종료시간 : ?:??       걸린시간 : 대략 15분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    // first : 0의 갯수
    // second : 1의 갯수
    vector<pair<ll, ll>> dp(n);
    dp[0].first = 0;
    dp[0].second = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i].first = dp[i-1].first + dp[i-1].second;
        dp[i].second = dp[i-1].first;
    }

    cout << dp[n-1].first + dp[n-1].second;
    return 0;
}


// 첫 풀이  -  걸린시간 : 10분  ||  시도횟수 : 1회;
// #include <iostream>

// using namespace std;

// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     int n;
//     cin >> n;

//     long long result = 1, temp1 = 1, temp2 = 1;
//     for (int i = 3; i <= n; i++)
//     {
//         result = temp1 + temp2;
//         temp1 = temp2;
//         temp2 = result;
//     }


//     cout << result;

//     return 0;
// }