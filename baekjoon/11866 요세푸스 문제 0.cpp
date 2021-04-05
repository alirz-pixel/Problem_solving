#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, K, cnt = 1;
    cin >> N >> K;

    queue<int> josephus;

    for (int i = 1; i <= N; i++)
        josephus.push(i);


    cout << "<";
    while (josephus.front() != josephus.back())
    {
        if (cnt != K)
        {
            josephus.push(josephus.front());
            josephus.pop();
            cnt++;
        }

        else // if (cnt == K)
        {
            cout << josephus.front() << ", ";
            josephus.pop();

            cnt = 1;
        }
    }

    cout << josephus.front() << ">";

    return 0;
}