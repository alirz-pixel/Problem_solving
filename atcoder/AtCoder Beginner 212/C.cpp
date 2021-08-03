#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    long long int n, m, result, min = -1;
    cin >> n >> m;

    vector<pair<int, bool>> arr(n + m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = false;
    }

    for (int j = n; j < m + n; j++)
    {
        cin >> arr[j].first;
        arr[j].second = true;
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n + m; i++)
    { 
        if (arr[i].second != arr[i-1].second)
        {
            result = abs(arr[i].first - arr[i-1].first);

            if (result < min || min == -1)
                min = result;
        }
    }

    cout << min;
    return 0;
}