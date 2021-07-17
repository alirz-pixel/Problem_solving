/*
https://atcoder.jp/contests/abc208/tasks/abc208_b
*/

#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	

	long long int fact[12] = { 1, };
    for (int i = 1; i < 12; i++)
    {
        fact[i] = 1;
        for (int j = 1; j <= i; j++)
            fact[i] = fact[i] * j;
    }

    
    int P, result = 0;
    cin >> P;

    for (int i = 11; i >= 1; i--)
    {
        if (P / fact[i] >= 1)
        {
            result += (P / fact[i]);
            P %= fact[i];
        }
    }
    
    cout << result;
	return 0;
}