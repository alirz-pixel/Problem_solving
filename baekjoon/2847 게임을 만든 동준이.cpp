/*
백준 2847번 게임을 만든 동준이 || 실버4
https://www.acmicpc.net/problem/2847



현재 점수와 이전 점수를 비교했을 때,
이전 점수가 더 크다면 (현재 점수-1)이 되도록 업데이트를 시켜주면 된다.
(딱, 실버4 정도의 난이도)

이런 간단한 로직 덕분에 감소시킨 총 량을 구할 때도
[이전 점수] - [현재 점수]를 계속해서 더해나가면,
감소시킨 총 량을 구할 수 있게 되는 것이다.


시작시간 1:04
종료시간 1:09   걸린시간 : 5분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, result = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    
    for (int i = arr.size()-1; i > 0; i--)
        if (arr[i] <= arr[i - 1])
        {
            result += arr[i-1] - (arr[i]-1);
            arr[i-1] = arr[i]-1;
        }

    cout << result;

    return 0;
}