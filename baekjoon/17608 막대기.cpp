/*  2021-08-22  8:36
백준 17608번 막대기 || 브론즈2
https://www.acmicpc.net/problem/17608



42번 줄에 max 값을 수정하는 코드 대신
stick[i]만 적어서 오답처리가 되었다....

----------
재풀이 :
이전엔 vector로 풀었었는데,

이런 문제의 경우 스택으로 짰을 때
for문에 대한 고려를 하지 않아도 되서 빠르게 풀 수 있다.


for문으로 풀었을 경우 :
    for (int i = n - 2; i >= 0; i++)  

위의 처럼 i의 초기값을 n-2로 해야된다는 것을 조심해야되기 때문에
stack으로 푸는 것이 편하다.

시작시간 : 1:07
종료시간 : 1:14       걸린시간 : 7분  ||  제출횟수 : 2회
*/



#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, temp, result = 0, max = 0;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        st.push(temp);
    }

    while(!st.empty())
    {
        if (st.top() > max)
        {
            max = st.top();
            result++;
        }

        st.pop();
    }

    cout << result;
    return 0;
}