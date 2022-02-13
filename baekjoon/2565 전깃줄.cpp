/*  2022-02-12  
백준 2565번 전깃줄 || 골드5
https://www.acmicpc.net/problem/2565




시작시간 21:15
종료시간 21:45      걸린시간 : 30분  ||  시도횟수 : 3회
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int solve(vector<pii>& elec) {
    if (elec.size() == 1) {
        return 0;
    }

    // 정렬
    sort(elec.begin(), elec.end(), less<pii>());

    // LIS 구하기
    vector<int> _lis(elec.size(), 1);
    int tempMax, retMax = 0;

    for (int i = 0; i < _lis.size(); i++) {
        tempMax = 0;

        for (int j = i-1; j >= 0; j--) {
            if (elec[j].second < elec[i].second && tempMax <= _lis[j]) {
                tempMax = _lis[j] + 1;
                _lis[i] = tempMax;
            }
        }

        if (retMax < tempMax) {
            retMax = tempMax;
        }
    }

    return elec.size() - retMax;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int k;
    cin >> k;

    vector<pii> elec(k);
    for (auto &i : elec) {
        cin >> i.first >> i.second;
    }

    cout << solve(elec);
    return 0;
}