/*  2021-08-20  2:35
백준 2386번 도비의 영어 공부 || 브론즈2
https://www.acmicpc.net/problem/2386


회고
 - 띄어쓰기도 입력받을 수 있는 getline 함수를 까먹었다는 점.
 - 대문자도 same과 일치하는지 확인해야 했다는 점.

이 2개로 인해 ICPC에서 분명 틀렸습니다나 풀지 못했을 것이다..


시작시간 2:45
종료시간 2:51     걸린시간 : 6분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int cnt;
    string same, sentence;
    while (1)
    {
        cnt = 0;
        cin >> same;

        if (same == "#")
            break;
        
        getline(cin, sentence);

        for (int i = 0; i < sentence.size(); i++)
            if (same[0] - 'a' == sentence[i] - 'a' || same[0] - 'a' == sentence[i] - 'A')
                cnt++;

        cout << same << " " << cnt << "\n";
    }


    return 0;
}