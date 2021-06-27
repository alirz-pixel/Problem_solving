/*
백준 17298번 오큰수  || 골드 4
https://www.acmicpc.net/problem/17298

수열 A가 주어졌을 떄, 역순으로 판단하며

DP를 하나 만들어가지고, 각각의 오큰수를 같이 저장해야할 듯

1. 만약, 이전 값이 현재 값보다 크다면, 이전 값을 스택에 넣음
2. 만약, 이전 값이 현재 값보다 작다면, DP를 하나씩 탐색하며 현재 값 보다 큰 값을 찾는다.

(이 모든 케이스에 대해 MAX값을 하나 저장해두고 '-1' 처리를 할 것도 생각해야 할 듯)



출력 : 출력은 스택을 이용하여 배열 싹 돌면서 출력하면 될 듯



시작 시간 : 11:46
종료 시간 : 12:23, 총 제출횟수 : 2번  ||  걸린시간 : 37분 
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, MAX = 0;
    cin >> N;

    stack<int> st;
    vector<int> DP(N);
    vector<int> A(N);

    for (auto& i : A)
        cin >> i;

    
    st.push(-1);
    MAX = A[A.size() - 1];
    DP[A.size() - 1] = -1;
    for (int i = A.size() - 2; i >= 0; i--) // 맨 뒤의 값은 -1이 확정이므로
    {  
        if (A[i] < A[i + 1])
        {
            if (MAX < A[i + 1])
                MAX = A[i + 1];

            st.push(A[i + 1]);
            DP[i] = A[i + 1];
        }


        else if (A[i] > A[i + 1]) // 현재값이 이전값보다 큰 경우
        {
            if (A[i] >= MAX) // 그 현재값이 MAX값 보다 큰 경우
            {
                MAX = A[i];
                DP[i] = -1;
                st.push(-1);
                continue;
            }

            for (int j = i + 1; j < A.size(); j++)
                if (A[i] < DP[j])
                {
                    st.push(DP[j]);
                    DP[i] = DP[j];
                    break;
                }
        }

        else // 현재값과 이전값이 같은 경우
        {
            DP[i] = DP[i + 1];
            st.push(DP[i + 1]);
        }
    }


    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}