#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    // solve();
    queue<int> q;
	priority_queue<int, vector<int>, greater<int>> pq;

    int command, x;
    while (n--)
    {
        cin >> command;

        if (command == 1)
        {
			cin >> x;
			q.push(x);
        }

        else if (command == 2)
        {
			if (pq.empty())
			{
				pq.push(q.front());
				q.pop();
			}

			cout << pq.top() << "\n";
			pq.pop();
        }

        else if (command == 3)
		{
			while(!q.empty())
			{
				pq.push(q.front());
				q.pop();
			}
		}
    }

    return 0;
}