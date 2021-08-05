/*
백준 2312 수 복원하기 || 실버2
https://www.acmicpc.net/problem/2312


push_back 함수를 추가하여 시간복잡도를 늘릴 생각이었으나,

push_back 함수를 에라토스테네스의 체 알고리즘에 추가해버려
i * i < MAX 일 때만 추가되는 문제가 발생하였다.

그 결과 소수는 313까지만 있는 것으로 되어버렸고,
이에 따라 오답처리가 되었다.....

시작 시간 8:58
종료 시간 ?:?? (의미없음)   총 걸린 시간 : GAMEOVER  ||  제출 횟수 : 4번
*/


#include <iostream>
#include <vector>
const int MAX = 100000 + 1;

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    vector<bool> temp(MAX, false);
    vector<int> prime(MAX);
    int primeCnt = 0;
    
    temp[0] = temp[1] = true;
    for (int i = 2; i * i < MAX; i++)
    {
        if (temp[i] == true) continue;


        for (int j = i * i; j < MAX; j+=i)
            temp[j] = true;
    }

    for (int i = 2; i < MAX; i++)
        if (temp[i] == false)
            prime[primeCnt++] = i;


    int t, n, result;
    cin >> t;

    for (int j = 0; j < t; j++)
    {
        cin >> n;

        for (int i = 0; i < primeCnt; i++)
        {
            result = 0;

            if (n % prime[i] == 0)
            {
                while(n % prime[i] == 0)
                {
                    n /= prime[i];
                    result++;

                    if (n == 1)
                        break;
                }

                cout << prime[i] << " " << result << "\n";
            }
            
            if (n == 1)
                break;
        }
    }

    return 0;
}