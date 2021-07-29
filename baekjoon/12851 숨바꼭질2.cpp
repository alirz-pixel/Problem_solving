/*
백준 12851 숨바꼭질2 || 골드 5
https://www.acmicpc.net/problem/12851



전에 이 문제를 BFS로 풀었다는 것에 대한 기억이 남아있어
그대로 BFS로 푸려고 한다.


정답을 맞추는 과정에서
방문처리를 하지않아 오래 걸리는 케이스가 존재하였으며   -->  1실패

방문처리를 하였기 때문에 중복정답(다른 경로로 갔으나 같은 시간내에 현 지저메 방문한 것)이 인정되지 않음  -->  2실패 

시작 시간 : 10:05
종료 시간 : 10:37
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void BFS(int n, int k);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, k;
    cin >> n >> k;

    BFS(n, k);
    return 0;
}

void BFS(int n, int k)
{
    vector<pair<bool, int>> visited(200000);


    int size, resultTime = 0, resultCnt = 0;
    bool end = false;
    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        size = q.size();

        for (int i = 0; i < size; i++)
        {
            if (q.front() == k)
            {
                end = true;
                resultCnt++;
            }

            if (q.front() < k)
            {
                if (!visited[q.front() + 1].first || (visited[q.front() + 1].first && visited[q.front() + 1].second == resultTime))
                {
                    q.push(q.front()+1);
                    visited[q.front()+1].first = true;
                    visited[q.front()+1].second = resultTime;
                }

                if (!visited[q.front() * 2].first || (visited[q.front() * 2].first && visited[q.front() * 2].second == resultTime))
                {
                    q.push(q.front()*2);
                    visited[q.front()*2].first = true;
                    visited[q.front()*2].second = resultTime;
                }
            }

            if (q.front() != 0)
                if (!visited[q.front() - 1].first || (visited[q.front() - 1].first && visited[q.front() - 1].second == resultTime))
                {
                    q.push(q.front()-1);
                    visited[q.front()-1].first = true;
                    visited[q.front()-1].second = resultTime;
                }

            q.pop();
        }

        if (!end)
            resultTime++;
        else
            break;
    }

    cout << resultTime << "\n" << resultCnt;
}