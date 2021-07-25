/*
백준 11660 구간 합 구하기 5 || 실버 1
https://www.acmicpc.net/problem/11660



구간 합 구하기 2~3에서 사용한 알고리즘을 이용하되
y축에 대해서만 따로 고려해주면 될거라 생각한다.

결과를 출력하기 위해선 O(N) -> [정확히는 입력받은 y] 만큼의 연산이 추가적으로 필요하다
이 마저도 없애는 알고리즘(?)이 존재하는데, 시간이 지난 후 추가적인 연산을 필요로 하지 않고
입력이 주어지면 O(1)의 시간복잡도를 가지는 알고리즘 풀이도 해볼 계획이다.


시작 시간 : 4:39
종료 시간 : 4:49     총 시도횟수 : 1회  ||  걸린시간 : 10분
*/



#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int temp, result;
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;

    vector<vector<int>> sum(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> temp;
            
            sum[i][j] += sum[i][j - 1] + temp;
        }

    for (int i = 0; i < m; i++)
    {
        result = 0;

        cin >> y1 >> x1 >> y2 >> x2;
        for (int y = y1; y <= y2; y++)
            result += (sum[y][x2] - sum[y][x1 - 1]);

        cout << result << "\n";
    }
    return 0;
}