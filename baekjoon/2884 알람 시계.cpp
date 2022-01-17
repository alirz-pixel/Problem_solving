/*  2021-08-25  1:07
백준 2884번 알람 시계 || 브론즈3
https://www.acmicpc.net/problem/2884



분(m) 연산이 끝난 후, 0일 때를 고려하지 않아
오답처리를 당하게 되었다.


시작시간 : 1:07
종료시간 : 1:11       걸린시간 : 4분  ||  제출횟수 : 2회
*/




#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int h, m;
    cin >> h >> m;

    m = ((m + 60) - 45);
    if (m >= 60)
        m -= 60;
    else
        h--;

    if (h < 0)        
        h = 23;

    cout << h << " " << m;
    return 0;
}