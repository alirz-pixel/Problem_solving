#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, temp;
    cin >> n;

    vector<int> giveTime(n);
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++)
        cin >> giveTime[i];

    priority_queue<pair<int, int>> pqTime;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pqTime.push({-temp, i});
    }


    int max = n;
    pair<int, int> top;
    while(n)
    {
        top = pqTime.top();
        pqTime.pop();

        if (result[top.second] == 0)
        {
            result[top.second] = -top.first;
            n--;
        }
        pqTime.push({-(-top.first + giveTime[top.second]), (top.second+1) % max});
    }

    for (int i = 0; i < max; i++)
        cout << result[i] << "\n";
    return 0;
}