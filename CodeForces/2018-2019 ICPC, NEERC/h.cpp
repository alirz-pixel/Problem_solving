/*  2021-08-18  4:06
코드포스 '2018-2019 ICPC, NEERC'  문제 : H
https://codeforces.com/group/sPvRZDMiQz/contest/1070/problem/H



ICPC를 같이 준비하던 팀원의 풀이와 알고리즘 특강을 듣고난 뒤
풀어서 제출(정답) 자체의 의미는 없지만

맵을 이렇게도 사용할 수 있으며, substr 함수를 처음알게 되었다.
(map은 진짜 전설이다..)


시작시간 4:08
종료시간 4:18     걸린시간 : 10분  ||  제출시도 : 1회
*/


#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string, pair<int, string>> m;
void insertMap_SubString(string& input);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    string input;
    int n, q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;

        insertMap_SubString(input);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> input;

        if (m[input].first == 0)
            cout << "0 -\n";

        else
            cout << m[input].first << " " << m[input].second << "\n";
    }

    return 0;
}


void insertMap_SubString(string& input)
{
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 1; j <= input.size() - i; j++)
        {
            string subString = input.substr(i, j);

            if (m[subString].second != input)
                m[subString].first++;

            m[subString].second = input;
        }
    }
}