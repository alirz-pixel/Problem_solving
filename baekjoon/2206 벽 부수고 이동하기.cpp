/*
백준 2206 벽 부수고 이동하기 || 골드4
https://www.acmicpc.net/problem/2206

[재풀이]
오랜만에 알고리즘 문제를 풀어인지 상당히 오려걸렸으며,
보드의 사이즈가 1일 떄를 고려하지 않아 1번 틀리게 되었다.

나머지 부분들은 최단거리 BFS로 똑같이 풀면되지만,
벽을 부수고 지나왔는지, 부수지 않고 지나왔는지만 잘 체크하면 무난한 BFS 풀이로 풀 수 있다.


시작시간 22:00
종료시간 22:09   걸린시간 : 69분  ||  제출횟수 : 2회
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coord {
    int x;
    int y;
    bool isBreak;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(const int& n, const int& m, vector<string>& map);
int main (void) 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m;
    cin >> n >> m;

    vector<string> map(n);
    for (auto &i : map)
        cin >> i;

    if (n == 1 && m == 1)
        cout << 1;
    else
        cout << BFS(n, m, map);

    return 0;
}

int BFS(const int& n, const int& m, vector<string>& map) {
    queue<coord> q;
    
    vector<vector<vector<bool>>> v(n, vector<vector<bool>>(m, vector<bool>(2)));
    v[0][0][0] = true;
    q.push( {0, 0, false});

    int cnt = 0, size;
    coord front, next;
    while (!q.empty()) {
        size = q.size();
        cnt++;

        for (int i = 0; i < size; i++) {
            front = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                next.x = front.x + dx[dir];
                next.y = front.y + dy[dir];
                next.isBreak = front.isBreak;

                // cout << next.x << " " << next.y << " " << next.isBreak;

                // 종료조건 - 탈출
                if (next.y == n-1 && next.x == m-1)
                    return cnt + 1;

                // 경계선
                if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) {
                    // cout << "경계선 컷\n";
                    continue;
                }
                
                // 방문처리
                if (v[next.y][next.x][next.isBreak]) {
                    // cout << "방문처리 컷\n";
                    continue;
                }
                v[next.y][next.x][next.isBreak] = true;

                // 더이상 부수지 못함.
                if (map[next.y][next.x] == '1') {
                    if (next.isBreak) {
                        // cout << "벽 컷\n";
                        continue;
                    }

                    next.isBreak = true;
                }

                // cout << "\n";
                q.push(next);
            }
        }
    }

    return -1;
}



// ---- [이전풀이] ----

// 단지, 최단 거리를 구하는 미로문제에서
// 벽을 부술 수 있다는 점만 고려하면 된다.

// 즉, 벽을 부술 수 있는 기회를 1주고
// queue에는 벽을 부쉈는가 안 부쉈는가에 대한 정보를 추가해주면 된다.
// (visited 변수엔 벽을 부수고 방문했는지, 벽을 부수지 않고 방문했는지 2개를 다루면 된다.)

// [간단할수도 있는 응용문제를 음악을 들으면서 했더니 풀이 시간이 오래걸렸다.]

// 시작시간 11:42
// 종료시간 12:34   걸린시간 : 48분  ||  제출횟수 : 2회

/*
#include <iostream>
#include <queue>

using namespace std;

typedef struct _coord{
    int y;
    int x;
    int block;
} coord;

void BFS(const vector<string>& graph, int endY, int endX);
int main(void)
{
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // cout.tie(0);


    int n, m;
    cin >> n >> m;

    vector<string> graph(n);
    for (int y = 0; y < n; y++)
        cin >> graph[y];

    if (n == 1 && m == 1)
        cout << 1;
    else
        BFS(graph, n, m);

    return 0;
}


void BFS(const vector<string>& graph, int endY, int endX)
{
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, -1, 1 };


    // 3차원 배열 [y][x][뿌숴서 왔는지] 으로 해야함
    vector<vector<vector<bool>>> v(endY, vector<vector<bool>>(endX, vector<bool>(2, false)));
    int size, my, mx, mblock, result = 0;
    coord front;

    front.block = 1;
    front.x = 0;
    front.y = 0;

    queue<coord> q;
    q.push(front);
    v[front.y][front.x][1] = true;

    while(!q.empty())
    {
        result++;
        size = q.size();

        for (int i = 0; i < size; i++)
        {
            front = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                my = dy[j] + front.y;
                mx = dx[j] + front.x;
                mblock = front.block;


                if (my == endY-1 && mx == endX - 1)
                {
                    result++;
                    cout << result;

                    return;
                }

                if (my < 0 || mx < 0 || my >= endY || mx >= endX)
                    continue;

                if (v[my][mx][mblock])
                    continue;
                    

                if (graph[my][mx] == '1')
                {
                    if (mblock == 1) // 벽을 부술 수 있다면
                    {
                        mblock = 0;

                        q.push({my, mx, mblock});
                        v[my][mx][mblock] = true;
                    }
                }

                else
                {
                    q.push({my, mx, mblock});
                    v[my][mx][mblock] = true;
                }
            }
        }
    }   

    cout << "-1";
}
*/