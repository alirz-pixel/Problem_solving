/*
https://atcoder.jp/contests/abc208/tasks/abc208_a
*/

#include <iostream>
 
using namespace std;
 
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
	
 
	int A, B;
    cin >> A >> B;
 
	if ((A* 6) >= B && A<=B)
        cout<< "Yes";
 
	else
        cout<< "No";
 
	return 0;
}