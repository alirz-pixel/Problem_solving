/*
백준 15652번 N과 M(4) || 실버 3
https://www.acmicpc.net/problem/15652




시작시간 : 9:33
종료시간 : 9:47  || 총 시도횟수 : 1번,  걸린시간 : 14분
*/


#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> arr, int start, int end, int cntEnd, int cnt);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    backtracking(arr, 1, n, m, 0);

    return 0;
}


void backtracking(vector<int> arr, int start, int end, int cntEnd, int cnt)
{
    if (cnt == cntEnd)
    {
        for (int i = 0; i < cntEnd; i++)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }


    for (int i = start; i <= end; i++)
    {
        arr[cnt] = i;
        backtracking(arr, i, end, cntEnd, cnt + 1);
    }
}