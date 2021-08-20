/*  2021-08-20  10:05
백준 2467번 용액 || 골드5
https://www.acmicpc.net/problem/2467


처음에는 N과 M처럼 완전탐색을 하면 될 줄 알았으나,
입력크기가 100,000이라 안될 것이라 판단하였다.

그 다음으로 생각한 것이 투포인터 인데,
이 투포인터를 사용할 떄 sum이 0이 되는 경우를 고려하지 않아.
반복문이 종료되지 못하여 시간초과가 되버렸다......


시작시간 10:05
종료시간 10:24       걸린시간 : 19분  ||  시도횟수 : 2회
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    vector<long long int> arr(n), result(2);
    for (auto &i : arr)
        cin >> i;

    
    int start = 0, end = arr.size()-1;
    long long int sum, tmpMin = arr[start] + arr[end];

    result[0] = arr[start];
    result[1] = arr[end];
    while (start < end)
    {
        sum = arr[start] + arr[end];
        
        if (abs(tmpMin) > abs(sum))
        {
            tmpMin = sum;
            result[0] = arr[start];
            result[1] = arr[end];
        }

        if (sum == 0)
            break;

        else if (sum > 0)
            end--;

        else if (sum < 0)
            start++;
    }

    
    cout << min(result[0], result[1]) << " " << max(result[0], result[1]);
    return 0;
}