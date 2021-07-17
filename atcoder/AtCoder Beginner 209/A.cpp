/*
https://atcoder.jp/contests/abc209/tasks/abc209_a
*/

#include <iostream>
 
using namespace std;
 
int main(void)
{
    int A, B, temp;
    cin >> A >> B;
    temp = (B - A) + 1;
 
    if (temp < 0)
        cout << "0";
 
    else
        cout << temp;
 
    return 0;
}