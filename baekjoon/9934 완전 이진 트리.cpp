/*  2021-08-26 2:12
백준 9934번 풍선 터뜨리기 || 실버1
https://www.acmicpc.net/problem/9934


규칙은 이러하다.

주어진 n에 대하여
트리의 깊이가 1일 경우, 인덱스가 1부터 시작하여 반복-{깊이(1) x 2}가 전부 깊이가 1인 노드라는 규칙을 띄고있다.
트리의 깊이가 2인 경우, 인덱스가 2부터 시작하여 반복-{깊이(2) x 2}가 전부 깊이가 2인 노드라는 규칙을 띄고있다.

이를 일반화 하면
트리의 깊이가 n인 경우, 인덱스가 n부터 시작하여 반복-{2n}가 전부 깊이가 n인 노드라는 규칙을 얻을 수 있다.


시작시간 : 2:38
종료시간 : 3:00       걸린시간 : 22분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, temp;
    cin >> n;
    
    temp = (int)pow(2, n);
    vector<int> input(temp);
    for (int i = 1; i <= (temp-1); i++)
        cin >> input[i];

    
    int jump = 2;
    vector<vector<int>> result(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = jump/2; j <= temp-1; j += jump)
            result[i].push_back(input[j]);
        jump *= 2;
    }

    for (int i = n; i > 0; i--)
    {
        for(int j = 0; j < result[i].size(); j++) 
            cout << result[i][j] << " ";

        cout << "\n";
    }
    return 0;
}