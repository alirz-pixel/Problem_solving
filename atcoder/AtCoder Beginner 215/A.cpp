#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    string input, same = "Hello,World!";
    cin >> input;

    if (input == same)
        cout << "AC";

    else    
        cout << "WA";
    return 0;  
}