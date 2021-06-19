/*
계속 "22퍼에서 틀렸습니다." 문구가 출력되어 인터넷 검색을 통해 문제를 해결하였으나,
아직도 어느 부분에서 틀린지 모르겠다.

시작 시간 : 11시 33분
종료 시간 : 12시 43분   ==> 소요시간 : 1시간 10분,  총 시도 횟수 4번
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int cnt = 0;
    int N, M, x, y;
    cin >> N >> M;


    map<int, int> path;

    for (int i = 0; i < N + M; i++)
    {
        cin >> x >> y;
        path[x] = y;
    }
    
    vector<bool> visited(101);
    bool isend = false;

    queue<int> q;
    int q_size = 0, location, next;

    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            location = q.front();  q.pop();

            for (int move = 1; move <= 6; move++)
            {
                next = location + move;

                if (next > 100) break;
                if (next == 100) 
                {
                    isend = true;
                    break;
                }

                if (path[next] != 0 && !visited[next])
                {
                    visited[next] = true;
                    next = path[next];
                }

                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }

            if (isend) break;
        }
        
        cnt++;
        if (isend) break;
    }

    cout << cnt;
}