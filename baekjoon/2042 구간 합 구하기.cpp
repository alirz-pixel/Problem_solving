/*  2021-08-30  2:31
백준 2042번 구간 합 구하기  ||  골드1
https://www.acmicpc.net/problem/2042




알고리즘 특강 시간에 세그먼트 트리를 배우게되어
이와 관련된 문제를 풀게되었다.

아마 앞으로 세그먼트 트리 문제가 나오게 된다면,
특강시간에 주신 템플릿을 이용할 것 같다.


시작시간 : ??:??
종료시간 : ??:??        걸린시간 : ??   ||   시도횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;

struct seg {
	int n;
	using _T = long long;
	vector<_T> S;
	_T(*op)(_T, _T);
	_T e;
	seg(const vector<_T>& A, _T(*op)(_T, _T), _T e) :op(op), e(e) {
		n = A.size();
		S.resize(4 * n);
		init(A, 0, n - 1, 1);
	}
	_T init(const vector<_T>& A, int nodeleft, int noderight, int node) {
		if (nodeleft == noderight) {
			return S[node] = A[nodeleft];
		}
		int mid = (nodeleft + noderight) / 2;
		return S[node] = op(init(A, nodeleft, mid, node * 2),
			init(A, mid + 1, noderight, node * 2 + 1));
	}

	_T query(int left, int right, int node, int nodeleft, int noderight) {
		if (right < nodeleft || noderight < left) return e;
		if (left <= nodeleft && noderight <= right) return S[node];

		int mid = (nodeleft + noderight) / 2;
		return op(query(left, right, node * 2, nodeleft, mid),
			query(left, right, node * 2 + 1, mid + 1, noderight));
	}
	_T query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	void update(int index, _T newvalue, int node, int nodeleft, int noderight) {
		if (index < nodeleft || noderight < index) return;
		if (nodeleft == noderight) {
			S[node] = newvalue;
			return;
		}
		int mid = (nodeleft + noderight) / 2;
		update(index, newvalue, node * 2, nodeleft, mid);
		update(index, newvalue, node * 2 + 1, mid + 1, noderight);
		S[node] = op(S[node * 2], S[node * 2 + 1]);
	}
	void update(int index, _T newvalue) {
		update(index, newvalue, 1, 0, n - 1);
	}
};

long long add (long long a, long long b) 
{
    return a+b;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> A(n);
    for (auto &i : A)
        cin >> i;

    seg segment(A, add, 0);


    // sovle();
    long long a, b, c;
    m += k;
    while (m--)
    {
        cin >> a >> b >> c;

        // 변경
        if (a == 1)
        {
            b--;
            segment.update(b, c);
        }
        // 구간합
        else
        {
            b--; c--;
            cout << segment.query(b, c) << "\n";
        }
    }
    return 0;
}