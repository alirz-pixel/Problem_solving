/*
백준 1107 리모컨 || 골드 5
https://www.acmicpc.net/problem/1107




시작시간 : 8:37
종료시간 : ?? - 대략 2시간 정도 소요
*/


#include <algorithm>
#include <iostream>

using namespace std;

int up(int n, bool button[], int num);
int down(int n, bool button[], int num);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    
    int n, m, temp, result;
    bool button[10] = { false, };

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        button[temp] = true;
    }

    if (n >= 100)
        result = n - 100;
    else
        result = 100 - n;

    
    if (m != 10)
    {
        result = min(result, up(n, button, m));
        result = min(result, down(n, button, m));
    }

    cout << result << "\n";
    return 0;
}

int up(int n, bool button[], int num)
{
    bool fail;
    int temp, digit, cnt = 0;


    if (num == 9 && button[0] == false)
    {
        if (n == 0)
            return 1;
        
        else
            return 1234567891;
    }

    if (n == 0)
    {
        n++;
        cnt++;
    }

    while(n > 0)
    {

        fail = false;
        temp = n;
        digit = 0;
        while(temp != 0)
        {
            if (button[temp % 10] == true)
            {
                fail = true;
                break;
            }

            temp /= 10;
            digit++;
        }

        if (!fail && n != 0)
        {
            return cnt + digit;
        }

        n++;
        cnt++;
    }

    return 1234567891;
}

int down(int n, bool button[], int num)
{
    bool fail;
    int temp, digit, cnt = 0;


    if (n == 0)
    {
        if (button[0] == false)
            return cnt + 1;

        else
            return 1234567891;
    }

    while(n >= 0)
    {
        fail = false;
        temp = n;
        digit = 0;
        while(temp != 0)
        {
            if (button[temp % 10] == true)
            {
                fail = true;
                break;
            }

            temp /= 10;
            digit++;
        }

        if (!fail)
        {
            if (n == 0 && button[0] == false)
                return cnt + 1;
            else if (n == 0)
                return 1234567891;
            else
                return cnt + digit;
        }

        n--;
        cnt++;
    }

    return 1234567891;
}