/*  2021-08-20  1:26
백준 15903번 카드 합체 놀이 || 실버2
https://www.acmicpc.net/problem/15903



result 변수와, card1/card2 의 변수들을 long long int로 하지 않아
1차 시도에서 틀리게 되었다..

알고리즘 자체는 우선순위 큐를 뺐다가 더한 후, 넣었다가를 반복하며
카드를 합체하는 방식으로 진행했다.


------ 재풀이 (조금의 시간복잡도 개선 [그래봐야 1000번의 연산])

- 마지막에 우선순위 큐에 들어간 요소들을 다 더하는 것 대신
- 처음의 입력을 result에 전부 더한 후,
- 카드를 합체하는 과정에서 생긴 card1 + card2의 합 또한
- result에 더해, 추가적인 연산을 줄였다.


시작시간 1:26
종료시간 1:43     걸린시간 : 17분  ||  시도횟수 : 2회
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using LL = long long int;
using PQ = priority_queue<long long int, vector<long long int>, greater<long long int>>;

void cardFusion(PQ& pq, int m, LL result);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    LL result = 0;
    int n, m, temp;
    cin >> n >> m;

    PQ pq;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        result += temp;
        pq.push(temp);
    }


    cardFusion(pq, m, result);
    return 0;
}


void cardFusion(PQ& pq, int m, LL result)
{
    LL card1, card2, sum;
    for (int i = 0; i < m; i++)
    {
        card1 = pq.top();
        pq.pop();

        card2 = pq.top();
        pq.pop();

        sum = card1 + card2;

        result += sum;
        pq.push(sum);
        pq.push(sum);
    }

    cout << result;
}