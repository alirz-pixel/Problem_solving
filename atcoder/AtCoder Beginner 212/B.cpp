#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int cnt[10] = {0,}, weakTemp = 0;
    string x;

    cin >> x;
    for (int i = 0; i < 4; i++)
    {
        cnt[x[i] - '0']++;
        if (cnt[x[i] - '0'] == 4)
        {
            cout << "Weak";
            return 0;
        }

        if (i != 4)
        {
            if (x[i] == '9' && x[i+1] == '0')
                weakTemp++;

            else if ((x[i+1]-'0') == (x[i]-'0') + 1)
                weakTemp++;
        }
    }

    if (weakTemp == 3)
        cout << "Weak";
    else
        cout << "Strong";
    return 0;
}