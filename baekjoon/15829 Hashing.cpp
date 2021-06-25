/*
백준 15829번 Hashing  || 브론즈 2
https://www.acmicpc.net/problem/15829

시작 시간 : 5:43
종료 시간 : 5:58
*/

#include <iostream>
#include <string>

#define MOD 1234567891

using namespace std;

int main (void)
{
    long long int r = 1, result = 0;
    int L;
    string input;

    cin >> L;
    cin >> input;

    for (int i = 0; i < L; i++)
    {
        result += (((input[i] - 'a') + 1) * r) % MOD;

        r *= 31;
        r %= MOD;
    }

    cout << result % MOD;

    return 0;
}