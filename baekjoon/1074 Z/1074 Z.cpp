/*
백준 1074번 Z  || 실버 1
https://www.acmicpc.net/problem/1074

시간제한이 0.5초인 것을 보고 재귀함수 호출을 4번 쪼개서 하면 안 되겠다고 판단함.
이점을 빠르게 인지하고 행과 열에 속한 부분만 재귀함수로 호출해서 풀었지만,
1. 필요 없는 배열의 선언으로 인해 첫 메모리 초과가 발생
2. 재귀 함수를 잘 못 선언하였는지, 배열을 없앴는데도 메모리 초과 발생

--> 이 때문에 반복문으로 풀게 됨

시작 : 11시 15분
종료 : 12시 22분
*/

#include <iostream>
#include <cmath>

using namespace std;

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int N, r, c;
    
    cin >> N >> r >> c;
    int maxIndex = pow(2, N);

    int length, cnt = 0;
    int H_Start = 0, W_Start = 0;
    int H_End = maxIndex, W_End = maxIndex;

    while (true)
    {
        length = H_End - H_Start;

        if (H_Start == r && W_Start == c)
        {
            cout << cnt;
            break;
        }

        // 2사분면
        if (H_Start + (length / 2) > r && W_Start + (length / 2) > c)
        {
            H_End = H_Start + (length / 2);
            W_End = W_Start + (length / 2);
        }

        // 1사분면
        else if (H_Start + (length / 2) > r && W_Start + (length / 2) <= c)
        {
            H_End = H_Start + (length / 2);
            W_Start = W_Start + (length / 2);
            cnt += pow((length / 2), 2);
        }

        // 3사분면
        else if (H_Start + (length / 2) <= r && W_Start + (length / 2) > c)
        {
            H_Start = H_Start + (length / 2);
            W_End = W_Start + (length / 2);
            cnt += pow((length / 2), 2) * 2;
        }

        // 4사분면
        else if (H_Start + (length / 2) <= r && W_Start + (length / 2) <= c)
        {
            H_Start = H_Start + (length / 2);
            W_Start = W_Start + (length / 2);
            cnt += pow((length / 2), 2) * 3;
        }
    }

    return 0;
}