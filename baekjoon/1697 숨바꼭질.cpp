/*
백준 1697번 

첫 시도 걸린시간 : 10분
 - 메모리 초과 : DP문제와 같이 이미 확인했던 경로를 다시 확인하다보니 메모리 초과가 난 것 같다.

두번째 시도 걸린시간 : 17분
 - 시간 초과 : 전에 -1 을 했다면, 다음 상황에선 +1 (의미없는 연산)을 하지 않도록 코드를 추가하고 제출했으나
 - 첫 시도와 같이 이미 확인했던 경로를 다시 확인하는 코드를 추가하지 않아 시간초과가 발생한 것 같다.

세번째 시도 걸린시간 : 13분
 - 백준에 나와있는 질문 검색을 통해 "map, set"을 이용해서 방문했던 곳을 또 방문하지 않도록 하는 법을 알게되었다.


의문점 : DP문제와 이 문제(BFS)의 차이점이 뭘까

총 걸린시간 : 40분
*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;

void bfs(int, int);

int main(void)
{
    int N, K;
    cin >> N >> K;

    bfs(N, K);

    return 0;
}

void bfs(int subin, int goal)
{
    int cnt = 0, cnt_temp = 0, sec = 0;
    int front, op;

    set<int> _set;
    queue<pair<int, int>> q;
    q.push({subin, 0}); 
    cnt++;
    _set.insert(subin);

    // pair의 seconde가 1일 경우, 전 상황에서 1을 더한 경우
    // pair의 seconde가 2일 경우, 전 상황에서 1을 뺀 경우

    while (!q.empty())
    {
        if (cnt == 0)
        {
            cnt = cnt_temp;
            cnt_temp = 0;
            sec++;
        }

        front = q.front().first;
        op = q.front().second;
        q.pop();
        cnt--;

        if (front == goal) break;


        if (front < goal)
        {
            if (_set.find(front * 2) == _set.end())
            {
                q.push({front * 2, 0});

                _set.insert(front * 2);
                cnt_temp++;
            }
        
            if (op != 2 && _set.find(front + 1) == _set.end())
            {
                q.push({front + 1, 1});

                _set.insert(front + 1);
                cnt_temp++;
            }
        }

        if  (front > 0 && op != 1 && _set.find(front - 1) == _set.end())
        {
            q.push({front - 1, 2});

            _set.insert(front - 1);
            cnt_temp++;
        }
    }

    cout << sec;
}