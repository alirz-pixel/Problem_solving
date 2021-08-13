#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int q, m, money;
    cin >> q;

    vector<bool> v(q + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    deque<pair<int, int>> dq;

    vector<int> result;
    int cnt = 1, inputIndex = 0;

    for (int i = 0; i < q; i++)
    {
        cin >> m;

        if (m == 1)
        {
            cin >> money;
            pq.push({money, inputIndex});
            dq.push_back({money, inputIndex});

            inputIndex++;
        }

        else if (m == 2)
        {
            while(!dq.empty())
            {
                if (v[dq.front().second])
                    dq.pop_front();
                else
                    break;
            }

            result.push_back(dq.front().second+1);
            v[dq.front().second] = true;
            dq.pop_front();
        }

        else if (m == 3)
        {
            while(!pq.empty())
            {
                if(v[pq.top().second])
                    pq.pop();
                else
                    break;
            }

            result.push_back(pq.top().second+1);
            v[pq.top().second] = true;
            pq.pop();
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}