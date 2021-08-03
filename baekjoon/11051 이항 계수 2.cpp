/*
백준 11051 이항 계수 2 || 골드 5
https://www.acmicpc.net/problem/11051


... 페르마의 소정리와 분할정복을 통한 거듭제곱을
이용하여 풀었으나

이상하게도 오답이 나와 머리가 아팠는데
0팩토리얼이 1이라는 것을 잊고, 0으로 초기화 해버렸기 때문에
틀린 것이었다.;;

시작 시간 3:47
종료 시간 4:18   총 제출횟수 2번 || 걸린 시간 : 38분
*/


#include <iostream>
typedef long long int ll;
const long long int MOD = 10007;

using namespace std;

ll loop(ll x, ll expo);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    ll fact[1001] = {1, 1};
    for (int i = 2; i <= 1000; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    int n, k;
    cin >> n >> k;

    cout << (((fact[n] * loop(fact[n - k], MOD - 2)) % MOD) * loop(fact[k], MOD - 2)) % MOD;

    return 0;
}


ll loop(ll x, ll expo)
{
    if (expo == 1)
        return x % MOD;

    ll temp = loop(x, expo / 2) % MOD;
    if (expo % 2)
        return (((temp * temp) % MOD) * x) % MOD;

    else
        return (temp * temp) % MOD;
}