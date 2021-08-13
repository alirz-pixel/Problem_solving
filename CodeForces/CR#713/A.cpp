#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int t, n, temp, result;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a[2], index = 0;
        map<int, pair<int, int>> m;

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;

            m[temp].first++;
            m[temp].second = j + 1;
            if (m[temp].first == 1)
                a[index++] = temp;
        }

        for (int j = 0; j < 2; j++)
            if (m[a[j]].first == 1)
                cout << m[a[j]].second << "\n";
    }
    return 0;
}