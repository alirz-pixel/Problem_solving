/*  2021-08-22  2:27
백준 13904번 과제 || 골드3
https://www.acmicpc.net/problem/13904



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

2차 풀이 방법 :
 - 1. 과제의 점수가 높은 순으로 정렬한다.
 - 2. 과제의 점수가 높은 순으로 순회한다. 이 때
 - 2-1 만약, 현재 순회중인 이 과제의 마감일이 나온적이 없다면 방문처리를 해준 후, result 변수에 더해준다.
 - 2-2                                     나온적이 있다면 0보다 크고 마감일보다 작은 곳에 방문처리를 해주고 result 변수에 더해준다.
===============================


시작시간 2:10  &&  2:34
종료시간 2:15  &&  2:43        걸린시간 : 15분  ||  시도횟수 : 1회
                         2차 : 걸린시간 : 9분  ||  시도횟수 : 1회
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);

    
    int n;
    cin >> n;

    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i].second >> input[i].first;

    sort(input.begin(), input.end(), greater<pair<int,int>>());

    // solve();
    vector<bool> day(1001);
    int j, result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!day[input[i].second])
        {
            result += input[i].first;
            day[input[i].second] = true;
        }

        else
        {
            for (j = input[i].second; j > 0; j--)
            {
                if (day[j] == false)
                    break;
            }

            if (j != 0)
            {
                result += input[i].first;
                day[j] = true;
            }
        }
    }
    
    cout << result;
    return 0;
}