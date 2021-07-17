/*
https://atcoder.jp/contests/abc210/tasks/abc210_c
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int max, dp = 0;
    int n, k;
    cin >> n >> k;

    map<int, int> color;
    vector<int> candi(n);

    for (int i = 0; i < k; i++)
    {
        cin >> candi[i];

        if (color[candi[i]] == 0)
            dp++;

        color[candi[i]]++;
    }


    max = dp;
    for (int i = k; i < n; i++)
    {
        cin >> candi[i];

        color[candi[i - k]]--;
        if (color[candi[i - k]] == 0)
            dp--;

        if (color[candi[i]] == 0)
            dp++;

        color[candi[i]]++;


        if (max < dp)
            max = dp;
    }

    cout << max;
    return 0;
}