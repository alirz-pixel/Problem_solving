#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, result;
    cin >> n;

    vector<int> student(n*2);
    for (int i = 0; i < n*2; i++)
        cin >> student[i];

    sort(student.begin(), student.end());

    result = student[0] + student[n*2 - 1];
    for (int i = 1; i < n; i++)
        result = min(result, student[i] + student[n*2 - (1+i)]);

    cout << result;

    return 0;
}