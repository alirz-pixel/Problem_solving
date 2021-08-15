#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    if (1 <= n && n <= 125)
        cout << 4;

    else if (126 <= n && n <= 211)
        cout << 6;

    else if (212 <= n && n <= 214)
        cout << 8;
    return 0;
}