/*
https://atcoder.jp/contests/abc207/tasks/abc207_b
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    long long int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (B >= C * D)
    {
        cout << "-1";
        return 0;
    }

    long long int cyan = A, red = 0, cnt = 0;
    while (1)
    {
        if (cyan <= red * D)
            break;

        red += C;
        cyan += B;
        
        cnt++;
    }

    cout << cnt;

    return 0;
}