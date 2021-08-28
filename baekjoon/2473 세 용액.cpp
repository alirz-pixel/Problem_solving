/*  2021-08-28  10:20
백준 2473번 세 용액  ||  골드4
https://www.acmicpc.net/problem/2473



시간복잡도 계산을 잘못하여
N * log N 알고리즘으로 풀려고 했다가

제출시도 4번이나 틀리고나서야
시간복잡도가 N^2인 알고리즘으로 풀 수 있다는 것을 알게되어

이 이후 코드를 적는데 14분을 소요하여 코드를 제출하였다.


-----------
== 로직
 - for문으로 한 점을 움직이면서,
   그 점에 대해서 두 포인터를 진행하는 방식으로 문제를 풀었다.
   
   시간복잡도 O(N^2)
   

시작시간 : 11:26
종료시간 : 11:40       걸린시간 : 14분 (+1시간) ||  제출횟수 : 1회 (+4회)
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


    // input()
    int n;
    cin >> n;

    vector<long long int> water(n);
    for (auto &i : water)
        cin >> i;

    sort(water.begin(), water.end());
    
    // solve();
    long long int sum, min = abs(water[0] + water[1] + water[2]);

    int l, r, resultIndex[3] = { 0, 1, 2 };
    for (int i = 0; i < n-2; i++)
    {

        l = i+1;
        r = n-1;

        // 한 점을 고정한 후, 두포인터
        while (l < r)
        {
            sum = water[i] + water[l] + water[r];

            if (min > abs(sum))
            {
                min = abs(sum);

                resultIndex[0] = i;
                resultIndex[1] = l;
                resultIndex[2] = r;
            }

            if (sum > 0)
                r--;
            else
                l++;
        }
    }


    // output();
    for (auto i : resultIndex)
        cout << water[i] << " ";
    return 0;
}