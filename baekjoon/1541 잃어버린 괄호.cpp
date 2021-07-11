/*
백준 1541 잃어버린 괄호 || 실버 2
https://www.acmicpc.net/problem/1541


처음엔 string으로 입력을 받는다.
그 후, 입력받은 값을 역으로 탐색한다.

탐색 중..
1. 숫자일 경우
  - expo 만큼 10을 제곱해준 후, 현재 값을 곱하여 num에 더해준다.

2. 문자일 경우
  - push_front를 통해 현재까지 입력받은 값과 연산자를 넣어준다.


--------------------------------------------------
// 탐색이 종료되면
// 데큐에 담긴 인덱스를 0 ~ size만큼 돌면서
// 브루트포스를 한다.
--------------------------------------------------

--------------------------------------------------
// 브루트포스로 구현하던 도중, 모르는 부분이 생겨 다시 멈추고 고민했었는데
// 1. 뺄셈 앞에 있는 값은 
--------------------------------------------------


두번째로 생각한 것이 위의 것이지만 이 방식 또한 이해가 되지 않아
인터넷에서 코드를 제외한 힌트를 얻어왔는데, 되게 간단한 문제였다...
(방식. 덧셈을 먼저한 후에 뺄샘을 해준다.)

시작시간 : 10:25
종료시간 : 11:09  |  걸린 시간 : 44분, 총 시도횟수
*/



#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int expo = 1, num = 0, result = 0;
    string input;
    deque<pair<int, char>> dq;

    cin >> input;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        // 만약, 숫자인 경우
        if(isdigit(input[i]))
        {
            num += ((input[i] - '0') * expo);
            expo *= 10;
        }

        // 연산자인 경우
        else
        {
            if (dq.front().second == '+')
            {
                dq.pop_front();

                num += dq.front().first;
                dq.front() = {num, '0'};
            }

            else
                dq.push_front({num, '0'});

            dq.push_front({0, input[i]});

            expo = 1;
            num = 0;
        }
    }
    if (dq.front().second == '+')
    {
        dq.pop_front();
        num += dq.front().first;
        dq.front() = {num, '0'};
    }

    else
        dq.push_front({num, '0'});



    result = dq[0].first;
    for (int i = 2; i < dq.size(); i += 2)
        result -= dq[i].first;

    cout << result;

    return 0;
}