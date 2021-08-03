#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

    long long int x, temp = 0, result;
    int q, p;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> p;

        if (p == 1)
        {
            cin >> x;

            pq.push(x - temp);
        }
        
        else if (p == 2)
        {
            cin >> x;
            temp += x;
        }

        else
        {   
            result = pq.top() + temp;
            cout << result << "\n";
            pq.pop();
        }
    }
    return 0;
}