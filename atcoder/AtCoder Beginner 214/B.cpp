#include <iostream>

using namespace std;

int cnt = 0;

void backTracking(int s, int t, int tempsSum, int temp, int now);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int s, t;
    cin >> s >> t;

    backTracking(s, t, 0, 1, 0);
    cout << cnt;
    return 0;
}

void backTracking(int s, int t, int tempsSum, int temp, int now)
{
    if (now == 3)
    {
        if (tempsSum <= s && temp <= t)
            cnt++;
        return;
    }

    int i = 0;
    while (1)
    {
        if (tempsSum + i <= s)
            backTracking(s, t, tempsSum + i, temp * i, now + 1);
        else
            break;
        i = i + 1;
    }

    return;
}