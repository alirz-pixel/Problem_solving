/*  2021-08-17
백준 13305번 주유소 || 실버4
https://www.acmicpc.net/problem/12852

분류 : [그리디]


=============================================
멍청하게도 문제를 보면서 바로 overflow에 대해 생각했지만,
코드를 적다보니 까먹어.. 부분합 배열을 int로 선언하여 58점을 받게 되었다....

로직 :
그리디 알고리즘 답게 일단 정렬을 통해 기름값이 '가장 싼' 도시를 찾는다.
해당 도시에서 끝 또는 기름이 싼 도시로의 거리는 부분합으로 관리되고 있기 때문에
O(1)로 구할 수 있다. 

[ 거리 = {다음도시} - {지금도시} ]
[ 비용 = 거리 * 현재 기름 가격 ]
=============================================


시작시간  20:28
종료시간  20:43       걸린시간 : 15분  ||  제출횟수 : 2회
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, del;
	cin >> N;

	vector<long long> len(N);
	vector<pair<int, int>> money(N-1);

	len[0] = 0;
	for (int i = 1; i <= N-1; i++) {
		cin >> len[i];
		len[i] += len[i - 1];
	}

	for (int i = 0; i < N-1; i++) {
		cin >> money[i].first;
		money[i].second = i;
	}
	cin >> del;


	// solve
	sort(money.begin(), money.end(), less<pair<int,int>>());

	long long sol = 0, minIndex = N-1;
	for (auto i : money) {
		if (minIndex > i.second) {
			sol += (len[minIndex] - len[i.second]) * i.first; // 거리 * 가격
			minIndex = i.second;
		}
	}
	cout << sol;
	return 0;
}