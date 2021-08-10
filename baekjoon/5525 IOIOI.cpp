/*
백준 5525 IOIOI || 실버2
https://www.acmicpc.net/problem/5525


KMP 알고리즘을 겨우 학습한 후,
이걸 처음으로(예전에 풀었으나 기억이 없음)
시도해보는 문제임

시작시간 9:00
종료시간 9:14     걸린 시간 : 14분  ||  시도횟수 : 1회
*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

void make_table(vector<int>& p, const string& pattern);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);

    string input, pattern = "IOI";
    int n, m, result = 0;
    cin >> n >> m;
    cin >> input;


    for (int i = 1; i < n; i++)
        pattern += "OI";

    vector<int> p(pattern.size(), 0);
    make_table(p, pattern);

    int j = 0;
    for (int i = 0; i < input.size(); i++)
    {
        while (j > 0 && input[i] != pattern[j])
            j = p[j - 1];

        if (input[i] == pattern[j])
        {
            if (j == pattern.size() - 1)
            {
                result++;
                j = p[j];
            }
            else
                j++;
        }
    }

    cout << result;

    return 0;
}


void make_table(vector<int>& p, const string& pattern)
{
    int j = 0;

    for (int i = 1; i < pattern.size(); i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = p[j - 1];
        
        if (pattern[i] == pattern[j])
            p[i] = ++j;
    }
}