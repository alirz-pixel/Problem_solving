/*
백준 11866번 요세푸스 문제 0 || 실버 4
https://www.acmicpc.net/problem/11866


데큐를 선언해, K칸 움직일 때까지 앞에서 pop하고 뒤에 push 해준다.
 = (그냥 큐를 사용했어도 되었음)


시작시간 : 3:12
종료시간 : 3:21
*/


#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int cnt = 0;
    int N, K;
    cin >> N >> K;

    deque<int> DQ;
    for (int i = 1; i <= N; i++)
        DQ.push_back(i);

    
    cout << "<";
    while (!DQ.empty())
    {
        if (DQ.size() == 1)
            break;

        if (cnt == K - 1)
        {
            cnt = 0;
            cout << DQ.front() << ", ";
            DQ.pop_front();
            continue;
        }

        cnt++;
        DQ.push_back(DQ.front());
        DQ.pop_front();
    }  
    cout << DQ.front() << ">";

    return 0;
}