/*
https://atcoder.jp/contests/abc210/tasks/abc210_a
*/

#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    long long int result;
    int n, a, x, y;
    cin >> n >> a >> x >> y;


    if (n < a)
        result = (n * x);

    else
    {
        result = (a * x);
        result += ((n - a) * y);
    }

    cout << result;
    return 0;
}