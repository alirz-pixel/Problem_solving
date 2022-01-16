/* 
백준 1292번 쉽게 푸는 문제 || 실버5
https://www.acmicpc.net/problem/1292


잘 고민해보면 수학적으로도 접근 가능한 문제처럼 보이기는 하나
2중 반복문을 잘 활용하면 더 쉽게 풀 수 있는 문제이다.


시작시간 20:05
종료시간 20:14       걸린시간 : 9분  ||  시도횟수 : 1회
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int cnt = 1, now = 0, sum = 0;
    while (1) {
        for (int i = 0; i < cnt; i++) {
            now++;

            if (a <= now)
                sum += cnt;

            if (b <= now)
                break;
        }
        cnt++;

        if (b <= now)
            break;
    }
    
    cout << sum;
    return 0;
}