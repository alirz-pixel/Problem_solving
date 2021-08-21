#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    long long int n, expo = 1;
    cin >> n;

    int cnt = 0, result = 0;
    while(1)
    {
        if (expo <= n)
        {
            result = cnt;
            expo *= 2;
            cnt++;
        }

        else
            break;
    }

    cout << result;

    
    return 0;  
}