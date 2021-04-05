#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable (string pattern, int patternSize);
void KMP (string parent, string pattern, int parentSize, int patternSize);

int main(void)
{
    int N, M;
    string pattern = "";
    string S;

    cin >> N >> M;
    cin >> S;

    for (int i = 0; i < N; i++)
        pattern += "IO";
    pattern += "I";

    KMP(S, pattern, M, N*2+1);

    return 0;
}

vector<int> makeTable (string pattern, int patternSize)
{
    vector<int> table(patternSize, 0);
    int j = 0;

    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = table[j - 1];

        if (pattern[i] == pattern[j])
            table[i] = ++j;
    }

    return table;
}

void KMP (string parent, string pattern, int parentSize, int patternSize)
{
    vector<int> table = makeTable(pattern, patternSize);

    int cnt = 0;
    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
            j = table[j - 1];

        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                cnt++;
                j = table[j];
            }

            else
                j++;
        }
    }

    cout << cnt;
}