#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    float a, b;
    cin >> a >> b;

    cout << (((a - b) / 3) + b);
    return 0;
}