/*
백준 7569 토마토 || 실버 1
https://www.acmicpc.net/problem/7569


2차원이었던 토마토 문제를 풀었던 기억이 아직 살아있어
비교적 쉽게 풀 수 있었다.

이번 코드에서 잘한 점은
이전 토마토 문제에서는 모든 토마토가 익었는지 확인하기 위해
for 문을 통해 확인했었지만 이번 코드에선 cnt 라는 변수를 통해
cnt == (모든 칸의 수) 가 성립할 경우로 확인한 점이 잘한점이라 생각한다.
*/



#include <iostream>
#include <queue>

using namespace std;

typedef struct _Coord {
    int x;
    int y;
    int h;
} coord;


int BFS(queue<coord>& q, int xEnd, int yEnd, int hEnd, int& cnt);

bool visited[100][100][100] = { false, };
int box[100][100][100] = { 0, };
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    coord temp;
    queue<coord> q;
    int x, y, h, cnt = 0, result;
    cin >> x >> y >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < x; k++)
            {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1)
                {
                    temp.h = i;
                    temp.y = j;
                    temp.x = k;

                    cnt++;
                    visited[i][j][k] = true;
                    q.push(temp);
                }

                else if (box[i][j][k] == -1)
                    cnt++;
            }

    result = BFS(q, x, y, h, cnt);

    if ((x * y * h) == cnt)
        cout << result;

    else
        cout << "-1";

    return 0;
}

int BFS(queue<coord>& q, int xEnd, int yEnd, int hEnd, int& cnt)
{
    // 위, 아래, 상, 하, 좌, 우 
    int dh[6] = { 1, -1, 0, 0, 0, 0 };
    int dy[6] = { 0, 0, 1, -1, 0, 0 };
    int dx[6] = { 0, 0, 0, 0, -1, 1 };


    int size, day = -1;
    coord top, nextMove;

    while(!q.empty())
    {
        size = q.size();
        
        for (int i = 0; i < size; i++)
        {
            top = q.front();  q.pop();

            for (int j = 0; j < 6; j++)
            {
                nextMove.h = top.h + dh[j]; // h
                nextMove.y = top.y + dy[j]; // y
                nextMove.x = top.x + dx[j]; // x


                if (nextMove.h < 0 || nextMove.y < 0 || nextMove.x < 0 || nextMove.h >= hEnd || nextMove.y >= yEnd || nextMove.x >= xEnd)
                    continue;

                if (visited[nextMove.h][nextMove.y][nextMove.x] == true)
                    continue;

                if (box[nextMove.h][nextMove.y][nextMove.x] != 0)
                    continue;

                visited[nextMove.h][nextMove.y][nextMove.x] = true;
                box[nextMove.h][nextMove.y][nextMove.x] = 1;
                q.push(nextMove);
                cnt++;
            }
        }

        day++;
    }

    return day;
}