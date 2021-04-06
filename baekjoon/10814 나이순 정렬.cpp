#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, i;
    cin >> N;

    vector<pair<int, pair<int, string>>> info(N);
    for (i = 0; i < N; i++)
    {
        cin >> info[i].first >> info[i].second.second;
        info[i].second.first = i;
    }
        
    sort(info.begin(), info.end());

    for (i = 0; i < N; i++)
        cout << info[i].first << " " << info[i].second.second << "\n";

    return 0;
}