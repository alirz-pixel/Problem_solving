/*
백준 14500 테트로미노 || 골드 5
https://www.acmicpc.net/problem/14500


입력의 최댓값이 500이므로, O(N^2)으로도
풀 수 있다고 생각한다.

따라서 첫 시도는 이를 근거로 알고리즘을 짰다.


= 도형이 대칭도 가능하다는 것을 생각하지 못하여 
  첫 시도를 틀리게 되었다.

시작시간 : 4:30
종료시간 : 5:32  || 총 소요시간 : 1시간 2분, 총 시도 횟수 : 2회
*/



#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
} block_xy;

block_xy block[19][4] = {
 // L
 {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 0 }},
 {{ 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 }},
 {{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 }},
 {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 }},
 // L 대칭
 {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 }},
 {{ 1, 0 }, { 1, 1 }, { 1, 2 }, { 0, 2 }},
 {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }},
 {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }},
 
 // Z
 {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }},
 {{ 0, 1 }, { 1, 1 }, { 1, 0 }, { 2, 0 }},
 // Z 대칭
 {{ 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 }},
 {{ 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }},

 // ㅜ
 {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 }},
 {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 }},
 {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 1, 0 }},
 {{ 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 }},

 // ㅡ
 {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }},
 {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }},

 // 네모
 {{ 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 }}
};


int find(vector<vector<int>>& arr, int y, int x, int endX, int endY);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m, temp, max = 0;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            cin >> arr[y][x];


    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)   
        {
            temp = find(arr, y, x, m, n);
            
            if (max < temp)
                max = temp;
        }

    cout << max;
    return 0;
}

int find(vector<vector<int>>& arr, int y, int x, int endX, int endY)
{
    int max = 0, sum;
    int moveY = 0;
    int moveX = 0;

    for (int i = 0; i < 19; i++)
    {
        sum = 0;

        for (int j = 0; j < 4; j++)
        {
            moveX = x + block[i][j].x;
            moveY = y + block[i][j].y;

            if (x < 0 || y < 0 || moveX >= endX || moveY >= endY)
            {
                sum = 0;
                break;
            }

            sum += arr[moveY][moveX];
        }

        if (max < sum)
            max = sum;
    }

    return max;
}