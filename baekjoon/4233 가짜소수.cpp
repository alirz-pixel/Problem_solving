/*
백준 4233 가짜소수 || 골드 4
https://www.acmicpc.net/problem/4233


패르마의 소정리와 분할정복을 이용한 거듭제곱 파트를 공부하던 도중에 풀었기 때문에
크게 막히는 부분없이 쭉쭉 진행하였는데

시간복잡도를 고려하지 않은 채, 에라토스테네스의 채를 구현했다가
테스트 케이스가 실행되지 않아 사실상 1번 틀림셈이나 다름 없게 되어버렸다.

시작 시간 4:22
종료 시간 4:42   총 제출횟수 1번 || 걸린 시간 : 20분
*/


#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n);
long long int loop(int x, int expo, const int MOD);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int p, a;

    while(1)
    {
        cin >> p >> a;

        if (p == 0 && a == 0) break;

        if(loop(a, p, p) == a)
        {
            if(isPrime(p))
                cout << "no\n";

            else
                cout << "yes\n";
        }
        else
            cout << "no\n";
    }

    return 0;
}


bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    
    return true;
}

long long int loop(int x, int expo, const int MOD)
{
    if (expo == 1)
        return x % MOD;

    long long int temp = loop(x, expo / 2, MOD) % MOD;
    if (expo % 2)
        return (((temp * temp) % MOD) * x) % MOD;

    else
        return (temp * temp) % MOD;
}