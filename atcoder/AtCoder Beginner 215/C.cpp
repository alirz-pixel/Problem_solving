#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> temp;
map<string, int> m;
string input;

int Permutation(int start, int end);
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);


    int k;
    cin >> input >> k;

    sort(input.begin(), input.end());

    Permutation(0, input.size());
    
    sort(temp.begin(), temp.end());
    cout << temp[k-1];

    return 0;  
}


int Permutation(int start, int end)
{
    if (m[input] == 0)
    {
        m[input] = 1;
        temp.push_back(input);
    }

    for (int i = 0; i < end; i++)
    {
        swap(input[i], input[end-1]);
        Permutation(0, end-1);
        swap(input[i], input[end-1]);
    }

    return 0;
}