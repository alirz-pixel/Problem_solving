/* 
백준 1043번 쉽게 푸는 문제 || 골드4
https://www.acmicpc.net/problem/1043


(재풀이 예약)


시작시간 **:**
종료시간 **:**       걸린시간 : *분  ||  시도횟수 : 5회
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int _find(int& x);

void solve(int& n, int& m, vector<int>& isTruth, vector<vector<int>>& party);
bool _union(int& x, int& y);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, cnt, temp;
    cin >> n >> m >> cnt;

    vector<int> isTruth(cnt);
    for (int i = 0; i < cnt; i++) {
        cin >> temp;
        temp--;
        isTruth[i] = temp;
    }

    vector<vector<int>> party(m, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            cin >> temp;
            temp--;
            party[i].push_back(temp);
        }
    }
    
    solve(n, m, isTruth, party);

    return 0;
}

int _find(int& x) {
    if (parent[x] == x)
        return x;

    parent[x] = _find(parent[x]);
    return parent[x];
}

bool _union(int& x, int& y) {
    int a = _find(x);
    int b = _find(y);

    if (a == b)
        return false;

    parent[a] = b;
    return true;
}

void solve(int& n, int& m, vector<int>& isTruth, vector<vector<int>>& party) {
    // 유니온 파인드 기본 설정
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // 파티에 참석한 사람들 합치기(union)
    int root;
    for (int i = 0; i < m; i++) {
        root = party[i][0];

        for (int j = 1; j < party[i].size(); j++) {
            _union(party[i][j], root);
        }
    }

    // 파티 개수 구하기
    bool yesTalk;
    int answer = 0;
    for (int i = 0; i < m; i++) {
        yesTalk = true;

        for (int j = 0; j < isTruth.size(); j++) {
            if (_find(party[i][0]) == _find(isTruth[j])) {
                yesTalk = false;
                break;
            }
        }

        if (yesTalk)
            answer++;
    }

    cout << answer;
}