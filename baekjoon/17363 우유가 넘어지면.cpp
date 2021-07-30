/*
백준 17363 우유가 넘어지면? || 브론즈 1
https://www.acmicpc.net/problem/17363



이 문제의 분류 자체가 구현문제라 딱히 어려움 없이 풀었으나
중간에 실수 하나가 들어가서 "출력 에러"가 발생했었다.


시작시간 : 8:23
종료시간 : 8:43   총 걸린시간 : 20분  ||  시도횟수 : 2번
*/



#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    vector<string> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    
    for (int x = m - 1; x >= 0; x--)
    {
        for (int y = 0; y < n; y++)
        {
            if (input[y][x] == '.')
                cout << ".";

            else if (input[y][x] == 'O')
                cout << "O";

            else if (input[y][x] == '-')
                cout << "|";

            else if (input[y][x] == '|')
                cout << "-";

            else if (input[y][x] == '/')
                cout << "\\";

            else if (input[y][x] == '\\')
                cout << "/";

            else if (input[y][x] == '^')
                cout << "<";

            else if (input[y][x] == '<')
                cout << "v";

            else if (input[y][x] == 'v')
                cout << ">";

            else if (input[y][x] == '>')
                cout << "^";
        }

        cout << "\n";
    }

    return 0;
}