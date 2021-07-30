/*
백준 15651 N과 M(3) || 실버 3
https://www.acmicpc.net/problem/15651



N과 M 시리즈에서 (1,2)를 풀었기 때문에 여기서 원하는 알고리즘이
back tracking이라는 것을 알고있으며,

소스 코드 또한 이미 짜봤기 때문에 손 쉽게 풀 수 있었다.

시작시간 : 9:48
종료시간 : 9:54   총 걸린시간 : 6분  ||  시도횟수 1번
*/


#include <iostream>
#include <vector>

using namespace std;

void loop(vector<int> arr, int n, int m, int cnt);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    loop(arr, n, m, 0);
    return 0;
}


void loop(vector<int> arr, int n, int m, int cnt)
{
    if (m == cnt)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[cnt] = i;
        loop(arr, n, m, cnt + 1);
    }

    return;
}