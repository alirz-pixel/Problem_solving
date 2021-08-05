/*
백준 16563 어려운 소인수분해 || 골드4
https://www.acmicpc.net/problem/16563


풀이 :
에라토스테네스의 체를 이용하여 소수가 아닌 수를
'최소의 소인수'로 만들어 버리는게 키 포인트였다.

그 이후, 입력이 주어지면
그 입력값에 따라 prime[n]을 해주면 n에서 나올 수 있는
최소의 소수가 나오기 때문에 이를 이용하면 되는 것이 
이 문제의 핵심이었다.

시작시간  7:26
종료시간  *:**    총 걸린시간 ?:??  ||  제출횟수 : 6회
*/



#include <iostream>
#include <vector>
#include <cmath>
const int MAX = 5000000 + 1;

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    vector<int> minprime(MAX);
    for (int i = 0; i < MAX; i++)
        minprime[i] = i;


    for (int i = 2; i <= sqrt(MAX); i++)
        if (minprime[i] == i) // 소수라면
            for (int j = i * i; j < MAX; j += i)
                if (minprime[j] == j) // 소수가 아니라면
                    minprime[j] = i;  // 소수로 만들어버린다. (제일 작은 소인수로 만든다)

    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        while(k > 1)
        {
            cout << minprime[k] << " ";
            k /= minprime[k];
        }

        cout << "\n";
    }

    return 0;
}