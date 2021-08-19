/*  2021-08-20  2:35
백준 15700번 타일 채우기 4 || 브론즈4
https://www.acmicpc.net/problem/15700



1x2 or 2x1 타일이 자치하는 공간은 2칸이다.
그렇기 때문에 n x m 공간이 주어졌을 떄, 

그 공간에 들어갈 수 있는 타일의 크기인 2로 나누어주면
이 공간에 들어갈 수 있는 타일의 개수를 알 수 있게 되는 것이다.
(뭔가 레이튼 같네)


시작시간 2:35
종료시간 2:40     걸린시간 : 5분  ||  시도횟수 : 2회
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    long long int n, m;
    cin >> n >> m;

    cout << (n * m) / 2;
    return 0;
}