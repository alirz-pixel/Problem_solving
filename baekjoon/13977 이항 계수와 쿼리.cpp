/*
백준 13977 이항 계수와 쿼리 || 골드 5
https://www.acmicpc.net/problem/13977


이 문제 또한 패르마의 소정리를 이용한 문제로 되게 간단하게 풀수 있었지만,
(((fact[n] * dPow(fact[k], MOD-2)) % MOD) * dPow(fact[n-k], MOD-2)) % MOD << "\n";
이 부분에서 fact[n]도 역원을 해줘야 되는지 알고 좀 헤맷던 부분이 있다.

다음에도 헷갈려하지 않도록 개념이나 공식을
다시 볼 필요성을 느끼게 되었다.

시작 시간 4:50
종료 시간 4:42   총 제출횟수 1번 || 걸린 시간 : 8분
*/


#include <iostream>
#include <vector>
typedef long long int ll;
const ll MOD = 1000000007;

using namespace std;

ll dPow(int x, int expo);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    vector<ll> fact(4000001, 1);
    for (int i = 1; i <= 4000000; i++)
        fact[i] = (fact[i-1] * i) % MOD;


    int m, n, k;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> n >> k;

        cout << (((fact[n] * dPow(fact[k], MOD-2)) % MOD) * dPow(fact[n-k], MOD-2)) % MOD << "\n";
    }
    return 0;
}


ll dPow(int x, int expo)
{
    if (expo == 1)
        return x % MOD;


    ll temp = dPow(x, expo/2) % MOD;
    if (expo % 2)
        return (((temp * temp) % MOD) * x) % MOD;
    else   
        return (temp * temp) % MOD;
}