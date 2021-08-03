/*
백준 1946 신입 사원 || 실버1
https://www.acmicpc.net/problem/13977



처음에 문제접근을 잘못해서 시간이 좀 걸리게 되었으나,
도중에 다른 풀이가 생각나 빠르게 대처할 수 있었던 것 같다.

풀이 :
서류 심사 순위가 높은 순으로 정렬을 한다.
이후, 1위의 면접 순위를 기준으로 순회를 시작한다.
(min 값에 1위의 면접 순위를 기록한다.)

0 < j < n 까지 탐색한다.
이때 1위의 면접 순위보다 작은 사람이 있다면,
cnt에 1을 더해주고 다음 순회부터는 이 사람의 면접 순위를 기준으로 탐색한다.



시작 시간 8:21
종료 시간 8:43   총 시도횟수 : 1회  ||  걸린시간 : 22분
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int arr[100001];
    int t, n, input1, input2, min, cnt;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> input1 >> input2;

            arr[input1] = input2;
        }

        cnt = 1;
        min = arr[1];
        for (int j = 2; j <= n; j++)
            if (min > arr[j])
            {
                cnt++;
                min = arr[j];
            }

        cout << cnt << "\n";
    }
 
    return 0;
}