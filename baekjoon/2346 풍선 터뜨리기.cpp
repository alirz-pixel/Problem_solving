/*  2021-08-26 2:12
백준 2346번 풍선 터뜨리기 || 실버3
https://www.acmicpc.net/problem/2346



dequeue를 이용하여 종이에 적혀있는 값만큼 '이동'하는게 포인트다.
즉, 데큐에서의 '이동'은 '어디서 빼고, 어디에 넣을지' 라는 것을 의미한다.


따라서 종이에 적힌 수가 양수이면,
앞에서 빼고, 그 값을 뒤에다가 넣는다라는 의미가 된다.

반대로 음수이면
뒤에서 빼고, 그 값을 앞에다가 넣는다라는 의미이다.


여기서 주의할 점이 하나 생기는데,
풍선을 터뜨릴 땐 데큐에서 요소가 하나 사라지는 것이 되므로
종이의 적힌 값을 { 1씩 빼거나, 1씩 더하는 } 연산을 추가적으로 해줘야 된다는 점이다.

이 점만 조심한다면, 쉽게 풀 수 있다.



시작시간 : 2:12
종료시간 : 2:23       걸린시간 : 11분  ||  제출횟수 : 1회
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int n, temp;
    cin >> n;

    deque<pair<int, int>> deq;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        deq.push_back({temp, i});
    }


    // solve();
    int front;
    while(!deq.empty())
    {
        // 풍선 터트리기
        front = deq.front().first;
        cout << deq.front().second << " ";
        deq.pop_front();



        // 터트린 풍선에 있던 종이의 적힌 수 만큼 이동
        // 풍선에 안에 적힌 종이가 양수일 때
        if (front > 0)
        {
            front--;
            while(front--)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else
        {
            front++;
            while(front <= 0)
            {
                deq.push_front(deq.back());
                deq.pop_back();
                front++;
            }
        }
    }
    return 0;
}