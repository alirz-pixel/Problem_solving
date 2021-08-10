/*
백준 2902 KMP는 왜 KMP일까? || 브론즈2
https://www.acmicpc.net/problem/2902


.... 오랜만에 브론즈 문제를 푸니
힐링한 기분이 들었다.

시작시간 9:42
종료시간 9:45     걸린시간 : 3분  ||  시도횟수 : 1회
*/



#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    string input, result;
    cin >> input;

    result += input[0];
    for (int i = 1; i < input.size(); i++)
    {
        if(input[i-1] == '-')
            result += input[i];
    }

    cout << result;
    return 0;
}