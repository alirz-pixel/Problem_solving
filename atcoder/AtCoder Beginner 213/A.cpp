#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int a, b, result;
    cin >> a >> b;

    result = a ^ b;
    cout << result;
    return 0;
}