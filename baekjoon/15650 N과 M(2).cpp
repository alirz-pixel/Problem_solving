/*
백준 15650번 N과 M(2) || 실버 3
https://www.acmicpc.net/problem/15650





시작시간 : 7:58
종료시간 : 9:27  || 총 시도횟수 : 1번,  걸린시간 1시간 30분..
*/


#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> result, int start, int end, int cntEnd, int cnt);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        vector<int> result(n);
        result[0] = i;

        permutation(result, i, n, m, 1);
    }

    return 0;
}

void permutation(vector<int> result, int start, int end, int cntEnd, int cnt)
{
    if (cntEnd == cnt)
    {
        for(int i = 0; i < cntEnd; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }

    int cntTemp = cnt + 1;
    for (int i = start + 1; i <= end; i++)
    {
        result[cnt] = i;
        permutation(result, i, end, cntEnd, cntTemp);
    }
}