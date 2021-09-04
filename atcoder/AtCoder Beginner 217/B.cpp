#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);

    map<string, bool> m;
    string input;


    for (int i = 0; i < 3; i++)
    {
        cin >> input;
        m[input] = true;
    }

    string same[4] = { "ABC", "ARC", "AGC", "AHC" };
    for (int i = 0; i < 4; i++)
    {
        if (!m[same[i]])
        {
            cout << same[i];
            break;
        }
    }
    return 0;
}