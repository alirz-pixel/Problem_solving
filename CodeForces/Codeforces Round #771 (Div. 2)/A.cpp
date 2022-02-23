/*  2021-08-18  3:33
코드포스 Round #771 (Div. 2)  문제 : A
https://codeforces.com/contest/1638/problem/A

분야 : [constructive algorithm, 그리디, 수학]


===========================================

영어 해석의 이슈로 reverse를 해야할 것을
계속 swap을 하여 틀리게 되었다...

그래도 이 문제 덕분에 reverse 함수에 대해 알게 되었다.

=============================================


시작시간 3:33
종료시간 4:38     걸린시간 : 65분  ||  제출시도 : 5회
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);

        for (auto &i : arr) {
            cin >> i;
        }

        bool findL = false;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (!findL && arr[i] != i+1) {
                findL = true;
                l = i;
            } else if (findL && arr[i] == l+1) {
                r = i;
                break;
            }
        }

        reverse(arr.begin() + l, arr.begin() + r + 1);

        for (auto i : arr) {
            cout << i << " ";
        } cout << "\n";
    }
 
    return 0;
}