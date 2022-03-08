/*
백준 5052 전화번호 목록 || 골드4
https://www.acmicpc.net/problem/5052


일관성을 판단하기 위한 접두어들에 대해서
table을 새로 업데이트해주면서
KMP를 완전 탐색 시키면 될 것이라 판단.

허나, 그냥 인덱스 하나하나 비교하는거랑 다를 것이 없다고 생각이 됨
(접두사만 판별하므로)

그래서 인터넷에 검색하여 풀이를 보았는데 거기선
set을 이용해 접두사를 계속 set에 등록시키는 방법을 사용함.



시작시간 10:18
종료시간 **:**
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    bool result;
    int t;
    cin >> t;

    while (t--)
    {
        result = false;
        int n;
        cin >> n;

        vector<pair<int, string>> input(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i].second;
            input[i].first = input[i].second.size();
        }

        sort(input.begin(), input.end());
        
        unordered_set<string> s;
        s.insert(input[0].second);

        for (int i = 1; i < n; i++)
        {
            string temp;
            
            for (int j = 0; j < input[i].first; j++)
            {
                temp += input[i].second[j];
                if (s.find(temp) != s.end())
                {
                    result = true;
                    cout << "NO\n";
                    break;
                }
            }

            if (result)
                break;

            s.insert(temp);
        }

        if (!result)
            cout << "YES\n";
    }

    return 0;
}