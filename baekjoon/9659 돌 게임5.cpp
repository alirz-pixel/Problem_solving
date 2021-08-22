/*  2021-08-22  8:36
백준 9659번 돌 게임5 || 실버2
https://www.acmicpc.net/problem/9659



시작시간 : 8:38
종료시간 : 8:40     걸린시간 : 2분  ||  제출횟수 : 1회
*/



#include <iostream>

using namespace std;

int main(void)
{   
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    long long int n;
    cin >> n;

    if (n % 2)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}