/*
백준 1107 리모컨 || 골드5
https://www.acmicpc.net/problem/1107



          22일 전,  재풀이
시작시간 : 8:37     7:57
종료시간 : ?:??     8:30

걸린시간 : 대략 2시간 정도 소요 -> 33분
시도횟수 : 2회                 -> 2회
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int divided(vector<bool> broken, int n);
int down(vector<bool> broken, int n, int result);
int up(vector<bool> broken, int n, int result);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, m, temp, result;
    cin >> n >> m;

    vector<bool> broken(10, false);
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        broken[temp] = true;
    }

    // 그냥 + 또는 - 버튼만 누른 경우
    result = abs(n - 100);
    
    result = min(down(broken, n, result), result);
    result = min(up(broken, n, result), result);
    
    cout << result;

    return 0;
}


int divided(vector<bool> broken, int n)
{
    if (n == 0)
    {
        if(broken[0])
            return 0;

        else
            return 1;
    }


    int cnt = 0;
    while(n != 0)
    {
        if (broken[n % 10])
            return 0;
        
        n /= 10;
        cnt++;    
    }

    return cnt;
}

int down(vector<bool> broken, int n, int result)
{
    int temp, cnt = 0;

    while(1)
    {
        temp = divided(broken, n);
        if (temp)
        {
            cnt += temp;
            break;
        }


        cnt++;
        if (result <= cnt)
            return 987654321;

        n--;
        if (n < 0)
            return 987654321;
    }

    return cnt;
}

int up(vector<bool> broken, int n, int result)
{
    int temp, cnt = 0;
    


    while(1)
    {
        temp = divided(broken, n);
        if (temp)
        {
            cnt += temp;
            break;
        }


        cnt++;
        if (result <= cnt)
            return 987654321;

        n++;
    }

    return cnt;
}