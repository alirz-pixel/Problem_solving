/*
https://atcoder.jp/contests/abc207/tasks/abc207_c
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, cnt = 0;
    cin >> N;

    vector<int> t(N);
    vector<int> l(N);
    vector<int> r(N);

    for (int i = 0; i < N; i++)
        cin >> t[i] >> l[i] >> r[i];


    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (!(r[i] <= l[j] || r[j] <= l[i]))
            {
                cnt++;
                continue;
            }

            if (l[i] == l[j] || r[i] == r[j])
            {
                cnt++;
                continue;
            }

            if (l[i] == r[j])
            {
                if (t[i] == 1 || t[i] == 2)
                    if (t[j] == 1 || t[j] == 3)
                    {
                        cnt++;
                        continue;
                    }
            }

            if (r[i] == l[j])
            {
                if (t[i] == 1 || t[i] == 3)
                    if (t[j] == 1 || t[j] == 2)
                    {
                        cnt++;
                        continue;
                    }
            }
        }
    }

    cout << cnt;

    return 0;
}