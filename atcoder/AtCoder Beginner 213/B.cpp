#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    cout << arr[1].second;

    return 0;
}