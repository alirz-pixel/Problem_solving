#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int l, q;
    cin >> l >> q;

    // solve();
    set<int> cut;

    int c, x, temp;

    cut.insert(0);
    cut.insert(l);
    while (q--)
    {
        cin >> c >> x;

        if (c == 1)
            cut.insert(x);

        else
        {
            auto i = cut.upper_bound(x);
            temp = *i;

            --i;
            cout << temp - *i << "\n";
        }
    }


    return 0;
}