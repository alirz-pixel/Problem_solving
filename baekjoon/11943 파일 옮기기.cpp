/*  2021-08-20  4:42
백준 11943번 파일 옮기기 || 브론즈4
https://www.acmicpc.net/problem/11943





시작시간 4:42
종료시간 4:45         걸린시간 : 3분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int a, b, c, d;
    cin >> a >> b;  
    cin >> c >> d;

    cout << min(a+d, c+b);

    return 0;
}