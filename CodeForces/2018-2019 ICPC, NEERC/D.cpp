#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
 
    int n, k;
    cin >> n >> k;
 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
 
    
    // 쓰레기 처리하기
    long long int result = 0, temp;
    for (int i = 0; i < n - 1; i++)
    {
        temp = ceil((double)arr[i] / k);
        result += temp;

        arr[i+1] = (arr[i] + arr[i+1]) - (temp * k);
        if (arr[i+1] < 0)
            arr[i+1] = 0;
    }
    result += ceil((double)arr[n-1] / k);
    cout << result;
 
    return 0;
}