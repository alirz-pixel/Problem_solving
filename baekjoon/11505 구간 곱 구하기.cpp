/*  2021-08-30  2:41
백준 11505번 구간 곱 구하기  ||  골드1
https://www.acmicpc.net/problem/11505




세그먼트 트리 템플릿을 이용하는 도중에
생성자의 항등원을 어떻게 이용하는 지 잘 몰라
엄청 해매게 되었었다.

seg segment(A, multi, 1);
여기의 3번째 매개변수가 항등원인데,

합을 구하는 문제일 경우, 0;
곱을 구하는 문제일 경우, 1;
이런식으로 사용해야한다.

이 당시 나는 이 항등원을 0으로 세팅해버려서,
쿼리를 수행하다 리턴값이 없는 상황에서 [필요한 수] * 0 이 되버려
계속 이상한 출력('0')이 나왔었다.


시작시간 : ??:??
종료시간 : ??:??        걸린시간 : ??   ||   시도횟수 : 1회
*/



#include <iostream>
#include <vector>
const long long mod = 1000000007;

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

long long multi(long long a, long long b)
{
	a %= mod;
	b %= mod;
	
	return (a * b) % mod;
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


	// init();
	seg segment(A, multi, 1);

	// solve();
	long long a, b, c;

	m += k;
	while(m--)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			b--;
			segment.update(b, c);
		}

		else
		{
			b--; c--;
			cout << segment.query(b, c) << "\n";
		}
	}
	return 0;
}