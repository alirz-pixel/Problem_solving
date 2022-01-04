/*  2022-01-04  20:04
백준 1316번 그룹 단어 체커 || 실버5
https://www.acmicpc.net/problem/1316

=================================================

[이론]
입력으로 주어진 각 문자열에 대해서 '각 문자가 연속해서 나타나는 경우'를 체크하는 방법은
문자 하나하나를 순회하면서 해당 문자가 그 문자열에서 '처음'으로 등장했는지를 판단하면 된다.

[소스]
바로 직전에 탐색한 문자를 저장하는 previous 변수는 하나 세팅한 후,
previous의 값이 변할 때마다 '해당 문자에 대해 방문처리'를 해준다.

이후 previous와 현재 탐색중인 문자가 다른 경우가 발생하였을 때,
해당 문자를 방문한 적이 있는지 확인한다.

 -> 방문한 적이 있다면, 각 문자가 연속해서 나타나지 않음
 -> 방문한 적이 없다면, previous 값을 갱신 + 방문처리한 후 이어서 계속 탐색

=================================================

시작시간  20:04
종료시간  20:14       걸린시간 : 10분  ||  제출횟수 : 1회

*/


// ---- [ 재풀이 ] ----
#include <iostream>
#include <map>

using namespace std;

int solve(int n);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    cout << solve(n);


    return 0;
}

int solve(int n) {
    string input;
    int count = 0;
    bool isTrue;

    for (int i = 0; i < n; i++) {
        isTrue = true;
        cin >> input;

        map<char, bool> m;

        char previous = input[0];
        m[input[0]] = true;
        for (int j = 1; j < input.length(); j++) {
            // previous 갱신
            if (previous != input[j]) {
                // 이미 갱신된 적이 있다면
                if (m[input[j]]) {
                    isTrue = false;
                    break;
                }

                previous = input[j];
                m[input[j]] = true;
            }
        }

        if (isTrue)
            count++;
    }

    return count;
}





// ---- [ 이전 풀이 ] ----
// 2021-08-22  8:36

// 시작시간 : 1:57
// 종료시간 : 2:07       걸린시간 : 10분  ||  제출횟수 : 1회


// #include <iostream>
// #include <vector>

// using namespace std;

// bool check(string& input);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     string input;
//     int n, cnt = 0;
//     cin >> n;

//     while(n--)
//     {
//         cin >> input;

//         if (check(input))
//             cnt++;
//     }

//     cout << cnt;
//     return 0;
// }


// bool check(string& input)
// {
//     vector<int> alphabet(26, 0);

//     for (int i = 0; i < input.length(); i++)
//     {
//         if (alphabet[input[i] - 'a'] == 0 || alphabet[input[i] - 'a'] == i)
//             alphabet[input[i] - 'a'] = i+1;
        
//         else    
//             return false;
//     }

//     return true;
// }