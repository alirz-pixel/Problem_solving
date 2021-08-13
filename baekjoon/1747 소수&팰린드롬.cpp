/*
백준 1747 소수&팰린드롬 || 골드5
https://www.acmicpc.net/problem/1747



문제를 풀던 중, 답장을 해야하는 카톡으로 인해
문제 푸는데 걸린시간을 책정할수가 없게 되었다.

그리고 질문 검색을 미리 보고 제출하여 사전에 방지했지만,
MAX값을 100000으로 설정해놨어서
입력값이 1000000으로 주어졌다면, 틀렸습니다가 떴을 것이다.

시작시간 8:40
종료시간 9:27    걸린시간 47분  ||  시도횟수 1회
*/



#include <iostream>
#include <vector>
const int MAX = 2000000;

using namespace std;

bool same(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    vector<int> prime;
    vector<bool> prime_Check(MAX);
    for (int i = 2; i * i < MAX; i++)
    {
        if (prime_Check[i])
            continue;

        for (long long int j = i * i; j < MAX; j += i)
            prime_Check[j] = true;
    }

    for (int i = 2; i < MAX; i++)
        if (!prime_Check[i])
            prime.push_back(i);

    int n;
    cin >> n;

    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] >= n && same(prime[i]))
        {
            cout << prime[i];
            break;
        }
    }

    return 0;
}


bool same(int n)
{
    int temp = 0, nTmp = n;
    
    while(n != 0)
    {
        temp *= 10;
        temp += n % 10;

        n /= 10;
    }

    if (temp == nTmp)  
        return true;

    return false;
}