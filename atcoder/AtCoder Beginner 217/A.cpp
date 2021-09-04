#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    string s, t;
    cin >> s >> t;

    if (s < t)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}