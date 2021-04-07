#include <iostream>
#include <queue>

using namespace std;

struct Node {

    int importance; // 중요도를 위한 변수
    bool output;    // 문제에서 궁금해 하는 변수에게 지정

};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int importance, cnt;
    int T, N, M;
    cin >> T;

    Node temp;
    

    for (int i = 0; i < T; i++)
    {
        queue<Node> q;
        cin >> N >> M;
        
        // 사전 세팅하기
        cnt = 1;
        for (int j = 0; j < N; j++)
        {
            cin >> importance;

            temp.importance = importance;

            if (j == M) // 문제에서 궁금해 하는 변수라면
                temp.output = true;
            else
                temp.output = false;

            q.push(temp);
        }


        // 알고리즘 시작
        while (!q.empty())
        {
            importance = 0;

            // q에 들어있는 값 중 가장 큰 중요도값 찾기
            for (queue<Node> i = q; !i.empty(); i.pop())
            {
                if (importance < i.front().importance)
                    importance = i.front().importance;
            }

            if (importance == q.front().importance)
            {
                if (q.front().output)
                {
                    cout << cnt << "\n";
                    break;
                }

                else
                {
                    q.pop();
                    cnt++;
                }
            }

            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }

    return 0;
}