/*
백준 2108번 통계학  || 실버 4
https://www.acmicpc.net/problem/2108

이 문제를 통해 
cin.tie(NULL);
ios::sync_with_stdio(false);
cout.tie(NULL); 가 시간을 많이 줄여준다는 것을 알게되었으며,

map이 생각보다 시간을 많이 잡아먹는다는 것 또한 알게되었다.


시작시간 : 11:01
종료시간 : 12:00 -> 총 제출횟수 2회, 걸린시간 59분
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define MAX 400001

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int average = 0, middle = 0, many = 0, range = 0;
    int N, max = -4001, min = 4001, many_max = 0, many_count = 0, many_cnt = 0;
    cin >> N;

    vector<int> cnt(8002);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        average += arr[i];

        cnt[arr[i] + 4000]++;

        if (max < arr[i])
            max = arr[i];

        if (min > arr[i])
            min = arr[i];

        if (many_max < cnt[arr[i] + 4000])
        {
            many_max = cnt[arr[i] + 4000];
            many_cnt = 0; // 최빈수의 갯수
        }

        if (many_max == cnt[arr[i] + 4000])
            many_cnt++;
    }

    sort(arr.begin(), arr.end());

    // 평균구하기
    average = floor((average / (float)N) + 0.5);
    cout << average << "\n";

    // 중앙값 구하기
    middle = arr[N / 2];
    cout << middle << "\n";

    // 최빈값 구하기
    if (N == 1)
        cout << arr[0] << "\n";

    else
    {
        for (int i = 0; i < N; i += cnt[arr[i] + 4000])
        {
            if (cnt[arr[i] + 4000] == many_max)
            {
                if (many_count == 1 || many_cnt == 1)
                {
                    cout << arr[i] << "\n";
                    break;
                }

                else
                    many_count++;                
            }
        }
    }
    
    
    // 범위 구하기
    range = max - min;
    cout << range;

    return 0;
}