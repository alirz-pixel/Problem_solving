#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    bool b3 = false, b2 = false, h = false, hr = false;
    string s[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];

        if (s[i] == "2B")
            b2 = true;

        else if (s[i] == "3B")
            b3 = true;

        else if (s[i] == "HR")
            hr = true;

        else if (s[i] == "H")
            h = true;
    }

    if (b2 && b3 && hr && h)
        cout << "Yes";

    else
        cout << "No";

    return 0;
}