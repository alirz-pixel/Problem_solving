/*
백준 9012번 괄호 || 실버4
https://www.acmicpc.net/problem/9012


이 문제를 c++ 문법으로 풀기 위해 다시 풀어보았다.

이 과정에서 stack을 사용할 떄,
stack이 비어있는 상태에서 st.top()을 호출시키면 안된다는 것을
알게되었다.

시작시간 6:18   
종료시간 6:25       걸린시간 : 8분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <stack>

using namespace std;

void solve(const string& input)
{
    stack<char> st;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
            st.push(input[i]);

        else if (input[i] == ')')
        {
            if (st.empty())
            {
                cout << "NO\n";
                return;
            }

            if (st.top() == '(')
                st.pop();
        }
    }

    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int t;
    cin >> t;

    string input;
    while (t--)
    {
        cin >> input;
        solve(input);
    }

    return 0;
}