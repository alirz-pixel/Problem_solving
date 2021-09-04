#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    vector<int> input(n);
    for (auto &i : input)
        cin >> i;


    // solve();
    vector<int> result(n+1);
    for (int i = 1; i <= n; i++)
        result[input[i-1]] = i;

    for (int i = 1; i <= n; i++)
        cout << result[i] << " ";
    
    return 0;
}