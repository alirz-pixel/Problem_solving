/*
백준 1021번 회전하는 큐 || 실버 4
https://www.acmicpc.net/problem/1021


문제에서는 왼쪽으로 이동, 오른쪽으로 이동의 최솟값을 구하고 싶어했으니
이에 대해서 엄밀하게 생각해야될 것 같지만,

무지성으로 오른쪽으로만 이동해도 시간초과는 나지 않는데다
min(큐에 들어있는 사이즈 - 오른쪽으로 이동한 횟수, 오른쪽으로 이동한 횟수) 로 풀 수 있는 것 같다.
  = min(왼쪽으로 이동한 횟수, 오른쪽으로 이동한 횟수)


시작시간 : 2:23
종료시간 : 2:43
*/


#include <algorithm> 
#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie();
    ios::sync_with_stdio(false);
    cout.tie();


    int cnt = 0, cntTemp, delTemp = 0;
    int N, M, del;
    cin >> N >> M;

    deque<int> dequeue;
    for (int i = 1; i <= N; i++)
        dequeue.push_back(i);

    cin >> del;
    while(!dequeue.empty() && M > delTemp)
    {
        if (del == dequeue.front())
        {
            dequeue.pop_front();
            delTemp++;

            if (delTemp < M)
                cin >> del;

            continue;
        }
        
        cntTemp = 0;
        while (dequeue.front() != del)
        {
            cout << "why not??" << endl;
            dequeue.push_back(dequeue.front());
            dequeue.pop_front();
            cntTemp++;
        }

        cnt += min(cntTemp, (int)dequeue.size() - cntTemp);
    }
    
    cout << cnt;
    return 0;
}