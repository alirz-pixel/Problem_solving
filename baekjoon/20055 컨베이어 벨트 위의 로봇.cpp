/*
백준 20055 컨베이어 벨트 위의 로봇 || 실버1
https://www.acmicpc.net/problem/20055



도저히 모르겠어서 인터넷을 참고하여 풀었다....

참고한 사이트 : https://bloofer.net/87

시작시간  9:15
종료시간  10:31   총 걸린시간 : 76분  ||  제출횟수 : 1회(의미없음)
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<int>& belt, int n, int k, int cnt);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> belt(2 * n);
    for (auto &i : belt)
    {
        cin >> i;

        if (i == 0)
            cnt++;
    }

    solve(belt, n, k, cnt);

    return 0;
}


void solve(vector<int>& belt, int n, int k, int cnt)
{
    int result = 0, tempBelt, end = (2 * n) - 1, i;
    vector<bool> robot(2 * n);

    while (1)
    {
        // 1. 회전
        int tempBelt = belt[end];
        bool tempRobot = robot[end];

        for (i = end; i > 0; i--)
        {
            belt[i] = belt[i-1];
            robot[i] = robot[i-1];
        }
        belt[0] = tempBelt;
        robot[0] = tempRobot;

        // 회전 후, 내리는 위치에 로봇이 있다면 없애기
        if (robot[n-1]) robot[n-1] = false;


        // 2. 로봇의 이동
        for (i = n - 2; i >= 0; i--)
            if (robot[i] && !robot[i+1] && belt[i + 1] != 0)
            {
                swap(robot[i], robot[i + 1]);
                belt[i + 1]--;

                if (belt[i + 1] == 0) 
                    cnt++;
            }


        // 이동 후, 내리는 위치에 로봇이 있다면 없애기
        if (robot[n-1]) robot[n-1] = false;

        
        // 3. 로봇 올리기
        if (belt[0] != 0)
        {
            robot[0] = true;
            belt[0]--;

            if (belt[0] == 0)
                cnt++;
        }

        result++;

        // 벨트가 돌아가는 모습을 보는 코드
        // 위의 cout -> 내구도
        // 아래의 cout -> robot이 있는지,  1 : 있음  2 : 없음

        // cout << "\n";
        // for (int i = 0; i < 2 * n; i++) {
        //     cout << belt[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < 2 * n; i++) {
        //     cout << robot[i] << " ";
        // }
        // cout << "\n";

        if (cnt >= k)
            break;
    }

    cout << result;
}