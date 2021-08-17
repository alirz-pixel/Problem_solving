#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    long long int sum = 0;
    int n, k, same;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    same = sum / k;
    if (sum % k != 0)
    {
        cout << "No";
        return 0;
    }

    vector<int> result;
    int j = 0, temp;
    for (int i = 0; i < k; i++)
    {
        sum = 0;
        temp = 0;

        for (; j < n; j++)
        {
            temp++;
            sum += arr[j];

            if (sum > same)
            {
                cout << "No";
                return 0;
            }

            else if (sum == same)
            {
                j++;   
                result.push_back(temp);
                break;
            }
        }

    }

    cout << "Yes\n";
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";

    return 0;
}