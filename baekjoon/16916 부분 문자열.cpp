/*
백준 16916 부분 문자열 || 골드4
https://www.acmicpc.net/problem/16916


KMP 알고리즘 학습 후, 
KMP 알고리즘과 관련된 문제를 찾아 풀게되었다.

(즉, 알고리즘 분류를 알고있는 상태에서 문제를 풀음.)

시작시간 9:52
종료시간 9:57
*/



#include <iostream>
#include <vector>

using namespace std;

void make_table(vector<int>& p, const string& pattern);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    string input, pattern;
    cin >> input;
    cin >> pattern;

    vector<int> p(pattern.size(), 0);
    make_table(p, pattern);

    int j = 0;
    for (int i = 0; i < input.size(); i++)
    {
        while(j > 0 && input[i] != pattern[j])
            j = p[j-1];

        if (pattern[j] == input[i])
        {
            if (j == pattern.size() - 1)
            {
                cout << 1;
                return 0;
            }

            else
                j++;
        }
    }

    cout << 0;
    return 0;
}


void make_table(vector<int>& p, const string& pattern)
{
    int j = 0;
    for (int i = 1; i < pattern.size(); i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
            j = p[j-1];

        if (pattern[i] == pattern[j])
            p[i] = ++j;
    }
}