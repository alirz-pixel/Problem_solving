// 재풀이
/*
백준 14500 테트로미노 || 골드 5
https://www.acmicpc.net/problem/14500


저번 풀이의 피드백에서 이 문제를 DFS로 풀 수 있다는 것을 알게되어
다시 이 문제를 풀게되었다.

DFS를 이용하면 'ㅗ' 블럭을 제외한 나머지 블럭들은 전부 만들 수 있기 때문에
'ㅗ'블럭에 대해서만 잘 생각하면 된다.

하지만 나는 구현력이 딸려... 헛짓거리를 너무 많이 하였다...

시작시간 : ?:??
종료시간 : ?:??        걸린시간 : 대략 40분   ||   시도 횟수 : 3회
*/



#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int Max = 0, endY, endX;


void DFS(vector<vector<int>>& board, int y, int x, int depth, int sum, int preY, int preX);
void except(vector<vector<int>>& board, int y, int x);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    // input();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (auto &i : board)
        for (auto &j : i)
            cin >> j;

    // solve();
    endY = n;
    endX = m;

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            DFS(board, y, x, 0, 0, -1, -1);
            except(board, y, x);
        }

    cout << Max;
    return 0;
}


void DFS(vector<vector<int>>& board, int y, int x, int depth, int sum, int preY, int preX)
{
    if (depth == 4)
    {
        if (sum > Max)
            Max = sum;

        return;
    }

    if (y >= endY || y < 0 || x < 0 || x >= endX)
        return;

    for (int i = 0; i < 4; i++)
    {
        int my = y + dy[i];
        int mx = x + dx[i];

        if (my != preY || mx != preX)
            DFS(board, my, mx, depth+1, sum + board[y][x], y, x);
    }
}


void except(vector<vector<int>>& board, int y, int x)
{
    int temp;

    // ㅏ or ㅓ
    if (y + 2 < endY)
    {
        if (x+1 < endX)
        {
            temp = board[y][x] + board[y+1][x] + board[y+2][x];
            temp += board[y+1][x+1];

            if (temp > Max)
                Max = temp;
        }

        if (x > 0)
        {
            temp = board[y][x] + board[y+1][x] + board[y+2][x];
            temp += board[y+1][x-1];

            if (temp > Max)
                Max = temp;
        }
    }

    // ㅗ or ㅜ
    if (x+2 < endX)
    {
        if (y+1 < endY)
        {
            temp = board[y][x] + board[y][x+1] + board[y][x+2];
            temp += board[y+1][x+1];

            if (temp > Max)
                Max = temp;
        }

        if (y > 0)
        {
            temp = board[y][x] + board[y][x+1] + board[y][x+2];
            temp += board[y-1][x+1];

            if (temp > Max)
                Max = temp;
        }
    }
}



// /*
// 백준 14500 테트로미노 || 골드 5
// https://www.acmicpc.net/problem/14500


// 입력의 최댓값이 500이므로, O(N^2)으로도
// 풀 수 있다고 생각한다.

// 따라서 첫 시도는 이를 근거로 알고리즘을 짰다.


// = 도형이 대칭도 가능하다는 것을 생각하지 못하여 
//   첫 시도를 틀리게 되었다.

// 시작시간 : 4:30
// 종료시간 : 5:32  || 총 소요시간 : 1시간 2분, 총 시도 횟수 : 2회
// */



// #include <iostream>
// #include <vector>

// using namespace std;

// typedef struct {
//     int x;
//     int y;
// } block_xy;

// block_xy block[19][4] = {
//  // L
//  {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 0 }},
//  {{ 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 }},
//  {{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 }},
//  {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 }},
//  // L 대칭
//  {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 }},
//  {{ 1, 0 }, { 1, 1 }, { 1, 2 }, { 0, 2 }},
//  {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }},
//  {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }},
 
//  // Z
//  {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }},
//  {{ 0, 1 }, { 1, 1 }, { 1, 0 }, { 2, 0 }},
//  // Z 대칭
//  {{ 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 }},
//  {{ 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }},

//  // ㅜ
//  {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 }},
//  {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 }},
//  {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 1, 0 }},
//  {{ 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 }},

//  // ㅡ
//  {{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }},
//  {{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }},

//  // 네모
//  {{ 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 }}
// };


// int find(vector<vector<int>>& arr, int y, int x, int endX, int endY);
// int main(void)
// {
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     cout.tie(NULL);


//     int n, m, temp, max = 0;
//     cin >> n >> m;

//     vector<vector<int>> arr(n, vector<int>(m, 0));
//     for (int y = 0; y < n; y++)
//         for (int x = 0; x < m; x++)
//             cin >> arr[y][x];


//     for (int y = 0; y < n; y++)
//         for (int x = 0; x < m; x++)   
//         {
//             temp = find(arr, y, x, m, n);
            
//             if (max < temp)
//                 max = temp;
//         }

//     cout << max;
//     return 0;
// }

// int find(vector<vector<int>>& arr, int y, int x, int endX, int endY)
// {
//     int max = 0, sum;
//     int moveY = 0;
//     int moveX = 0;

//     for (int i = 0; i < 19; i++)
//     {
//         sum = 0;

//         for (int j = 0; j < 4; j++)
//         {
//             moveX = x + block[i][j].x;
//             moveY = y + block[i][j].y;

//             if (x < 0 || y < 0 || moveX >= endX || moveY >= endY)
//             {
//                 sum = 0;
//                 break;
//             }

//             sum += arr[moveY][moveX];
//         }

//         if (max < sum)
//             max = sum;
//     }

//     return max;
// }