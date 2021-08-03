#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int a, b;
    cin >> a >> b;

    if (0 < a && b == 0)
        cout << "Gold";

    if (a == 0 && 0 < b)
        cout << "Silver";
    
    if (0 < a && 0 < b)
        cout << "Alloy";
    return 0;
}