#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> a(4);

        for (int j = 0; j < 4; j++)
            cin >> a[j];

        sort(a.begin(), a.end(), less<int>());

        cout << a[0] * a[2] << "\n";
    }


    return 0;
}