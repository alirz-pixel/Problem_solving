/*
https://atcoder.jp/contests/abc210/tasks/abc210_b
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    bool trun = false; // false = 타카하시
    int n;
    string s;

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1')
            break;

        trun = !trun;
    }

    if (!trun)
        cout << "Takahashi";
    else
        cout << "Aoki";
    return 0;
}