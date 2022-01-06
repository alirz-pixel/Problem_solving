/*  2022-01-06  23:49
백준 19637번 IF문 좀 대신 써줘 || 실버3
https://www.acmicpc.net/problem/19637


1.
N과 M 모두 10의 5승이므로 순차탐색으로 풀게되면
10의 10승이 되버려 시간초과가 나게 될 것이다.

그래서 이 문제는 이분 탐색으로 풀어야 한다.


2.
전투력이 같은 경우 이분 탐색 과정에서 추가적인 처리가 필요해지게 되는데,
이는 입력받을 때부터 방문처리를 통해 걸러내면 쉽게 풀 수 있게 된다.

(다만 필자는 이분탐색에 약하여 60분 이상이 걸리게 되었다... )
(-- 다시 기초부터 시작해야겠네.... --)


시작시간  -  22:41
종료시간  -  23:49      걸린시간 : 67분  ||  제출시도 : 2회
*/

#include <algorithm>
#include <iostream>
#include <deque>
#include <map>

using namespace std;

typedef pair<int, string> pis;

void solve(deque<pis>& dq, const int& n, const int& m);
int main(void) 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    pis input;
    deque<pis> dq;
    map<int, bool> m;
    for (int i = 0; i < N; i++) {
        cin >> input.second >> input.first;

        if (m[input.first])
            continue;

        m[input.first] = true; 
        dq.push_back({input.first, input.second});
    }

    solve(dq, N, M);

    return 0;
}

void solve(deque<pis>& dq, const int& n, const int& m)
{
    // 오름차순 정렬
    sort(dq.begin(), dq.end());

    int query;
    int start, mid, end;
    for (int i = 0; i < m; i++) {
        cin >> query;
        
        start = 0;
        end = dq.size();
        while (start <= end) {
            mid = (start + end) / 2;

            if (dq[mid].first > query) 
                end = mid - 1;

            else if (dq[mid].first == query)
                break;

            else
                start = mid + 1;
        }
        
        if (dq[mid].first < query) {
            if (mid == dq.size() - 1)
                cout << dq[mid].second;
            else
                cout << dq[mid+1].second;
        }
        else
            cout << dq[mid].second;

        cout << "\n";
    }
}