/*
https://atcoder.jp/contests/abc207/tasks/abc207_a
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> A(3);

    for (int i = 0; i < 3; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    cout << A[1] + A[2];


    return 0;
}