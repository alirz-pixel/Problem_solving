/*  2021-08-22  2:27
백준 13904번 과제 || 골드3
https://www.acmicpc.net/problem/16234



다른 업무를 같이하면서(친구랑 통화 및 노래) 풀었는데도 15분 만에 풀어서 그런지
기분이 오묘하다.  [티어가 잘 못 책정된거 같기도]


===========================
풀이 방법은 이러하다.
마감일을 고려하지 않아도 괜찮도록

마감일이 제일 여유로운 것 부터 시작하여
우선순위 큐에 넣는다.

한 마감일에 대한 입력값들을 우선순위 큐에 넣고나면,
그 중에서 제일 큰 값을 빼내어 result 변수에 더해준다.   (그냥 pq.pop() 하면 됨)

이렇게 0일까지 반복하면 쉽게 풀 수 있다.
===========================

시작시간 2:10
종료시간 2:15       걸린시간 : 15분  ||  시도횟수 : 1회
*/



#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<int> pq;
    vector<vector<int>> day(1001);

    int inputDay, inputEnd, maxDay = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> inputDay >> inputEnd;

        maxDay = max(inputDay, maxDay);
        day[inputDay].push_back(inputEnd);
    }


    int result = 0;    
    for (int i = maxDay; i > 0; i--)
    {
        for (int j = 0; j < day[i].size(); j++)
            pq.push(day[i][j]);


        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
    return 0;
}