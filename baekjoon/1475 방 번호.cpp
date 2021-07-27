/*
백준 1475 방 번호 || 실버 5
https://www.acmicpc.net/problem/1475


예전에 풀어본 문제이지만 
재채점 되었다길래 오랜만에 다시 풀어봄

(9가 입력된 경우에 6으로 처리되게 만들었으나,
 6이 입력된 경우에 result를 (cnt[6]+1 / 2)로 전처리하지 않아 틀리게 되었다.)

시작 시간 : 9:49
종료 시간 : 10:01    총 시도 횟수 : 2회  ||  걸린 시간 : 12분
*/



#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int cnt[9] = {0}, result = 0;
    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '9' || n[i] == '6')
        {
            cnt[6]++;

            if (((cnt[6]+1) / 2) > result)
                result++;
        }

        else
        {
            cnt[n[i] - '0']++;

            if (cnt[n[i] - '0'] > result)
                result++;
        }
    }

    cout << result;
    return 0;
}