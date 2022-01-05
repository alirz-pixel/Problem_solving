/*
백준 1182 부분수열의 합 || 실버2
https://www.acmicpc.net/problem/1182

[재풀이]
음수가 나올 수 있다는 점을 생각하지 못하여
2번 정도를 더 틀리게 되었다.

이전 풀이와 비교를 해보니 
배열을 복사하는 데에도 꽤 많은 시간이 걸린다는 것을 알게 되었다.

시작시간 - 20:42
제출시간 - 21:14    걸린시간 : 32분  || 시도횟수 : 3회
*/


#include <iostream>
#include <vector>

using namespace std;

void loop(vector<int>& arr, const int& S, const int& now, int& cnt, int sum);
int main(void) 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int N, S, cnt = 0;
    cin >> N >> S;

    vector<int> arr(N);
    for (auto &i : arr)
        cin >> i;

    for (int i = 0; i < N; i++) {
        loop(arr, S, i, cnt, arr[i]);
    }

    cout << cnt;

    return 0;
}

void loop(vector<int>& arr, const int& S, const int& now, int& cnt, int sum) {
    if (S == sum)
        cnt++;

    for (int i = now+1; i < arr.size(); i++) {
        loop(arr, S, i, cnt, sum+arr[i]);
    }

    return;
}


// ---- [이전풀이] ----

// backTracking 문제에서 배운 알고리즘을 여기서 적용하여
// 주어진 n개의 데이터를 '완전탐색'으로 전부 더한 후,
// s가 되는지 확인하는 방식으로 풀었다.

// 시작시간 10:38
// 종료시간 10:55    걸린시간 : 17분  || 시도횟수 : 1회


// #include <iostream>
// #include <vector>

// using namespace std;

// int cnt = 0;

// void backTracking(vector<int> arr, int n, int now, int sum, int s);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);
    

//     int n, s;
//     cin >> n >> s;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < n; i++)
//         backTracking(arr, n, i, arr[i], s);

//     cout << cnt;
//     return 0;
// }


// void backTracking(vector<int> arr, int n, int now, int sum, int s)
// {
//     if (sum == s)
//         cnt++;

//     if (now + 1 == n)
//         return;

//     for (int i = now + 1; i < n; i++)
//     {
//         backTracking(arr, n, i, sum + arr[i], s);
//     }

//     return;
// }