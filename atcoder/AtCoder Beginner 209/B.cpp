/*
https://atcoder.jp/contests/abc209/tasks/abc209_b
*/

#include <iostream>
#include <vector>
 
using namespace std;
 
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
 
 
    int n, money, temp, sum= 0;
    cin >> n >> money;
 
    for (int i= 1; i <= n; i++)
    {
        cin >> temp;
 
        if (i% 2 == 0)
            sum += (temp - 1);
 
        else
            sum += temp;
    }
 
    if (sum <= money)
        cout << "Yes";
 
    else
        cout << "No";
 
    return 0;
}