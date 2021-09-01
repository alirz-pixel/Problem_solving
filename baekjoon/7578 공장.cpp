/*  2021-09-01  8:29
백준 7578번 공장  ||  플레티넘5
https://www.acmicpc.net/problem/7578



세그먼트 트리를 문제를 풀고 싶어서 공장 문제를 고르게 되었다.
하지만 세그먼트 트리에 대한 이해력이 높지않아 인터넷을 좀 참고하게 되었다.

lineA를 순회하면서 lineB의 어디에 나오는 지 판단해야 하는데,
이 부분에서 N^2 -> N * log N -> N 이런식으로 고쳐가며 3번이나 틀리게 되었다.


그리고 lineB에서 lineA와 같은 값을 찾았다면, 세그먼트 트리에 그 인덱스의 값을
1로 만들어주고 j+1 ~ n까지 탐색하면서 1의 갯수를 세주면 되는 것이다.

   

시작시간 : 8:30
종료시간 : 9:00       걸린시간 : 30분  ||  제출횟수 : 3회
*/


#include <iostream>
#include <vector>

using namespace std;

struct seg {
	int n;
	using _T = int;
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


int add(int a, int b) {
    return a + b;
}


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    // input();
    int n, temp;
    cin >> n;

    vector<int> lineA(n);
    for (auto &i : lineA)
        cin >> i;
    
    vector<int> lineB(1000001);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        lineB[temp] = i;
    }


    // solve();
    int j;
    long long result = 0;

    vector<int> connect(n, 0);
    seg segment(connect, add, 0);
    for (auto i : lineA)
    {
        j = lineB[i];
        segment.update(j, 1);

        if (j != n-1)
            result += segment.query(j+1, n-1);
    }

    cout << result;
    return 0;
}