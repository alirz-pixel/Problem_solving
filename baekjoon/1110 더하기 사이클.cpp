/*  2021-08-25  1:27
백준 1110번 더하기 사이클 || 브론즈1
https://www.acmicpc.net/problem/1110


이전과 마찬가지로 문제를 제대로 보지 않고 풀다가
'주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수를 만들고'
부분을 반복문에 추가하여 18분이나 걸리게 되었다.



시작시간 - 20:12
종료시간 - 20:30       걸린시간 : 18분  ||  제출횟수 : 1회
*/


#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int startN, N, temp, cnt = 0;
    cin >> N;
    if (N < 10)
        N *= 10;

    startN = N;
    do {
        temp = N % 10;

        N = (temp * 10) + (((N / 10) + temp) % 10);
        cnt++;
    } while (startN != N);

    cout << cnt;

    return 0;
}





// ---- [ 이전 풀이 ] ----
// 2021-08-22  8:36

// .. 문제를 제대로 읽지 않고 풀어서 헛짓거리를 좀 많이 했다..

// 시작시간 : 1:27
// 종료시간 : 1:42       걸린시간 : 15분  ||  제출횟수 : 1회


// #include <iostream>

// using namespace std;

// void cycle(int& n);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     int n, tempN, cnt = 0;
//     cin >> n;
    
//     tempN = n;
//     do
//     {

//         cnt++;
//         cycle(n);

//     } while(tempN != n);

//     cout << cnt;
//     return 0;
// }


// void cycle(int& n)
// {
//     int sum = 0, temp = n % 10;

//     if (n < 10)
//     {
//         temp = n;
//         n *= 10;
//     }

//     while(n)
//     {
//         sum += n % 10;
//         n /= 10;
//     }

//     n = sum%10 + (temp*10);
//     return;
// }