/*  2022-02-16  21:00
백준 11000번 강의실 배정  ||  골드5
https://www.acmicpc.net/problem/2980


분야 : [자료구조, 그리디, 정렬, 우선순위 큐]


알고리즘 시간에서 그리디 파트를 배울 때,
Interval Scheduling과 관련하여 배운 내용으로

현재 교실 배정이 안된 수업 중, 시작 시간이 제일 빠른 수업을 고른 후
해당 수업을 가능한 교실에 배치하면 되는 알고리즘이다.
(가능한 교실이 없는 경우 새로운 교실에 배치)

이 알고리즘을 위해 정렬과 우선순위큐를 사용하면 쉽게 구현할 수 있다.


시작시간 : 21:00
풀이구상 : 21:12      제출시도 : 1회  ||  걸린시간 : 12분
*/



#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int solve(vector<pii> room);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	vector<pii> room(N);
	for (auto &i : room) {
		cin >> i.first >> i.second;
	}
	
	cout << solve(room);
	return 0;
}

int solve(vector<pii> room) {
	sort(room.begin(), room.end(), less<pii>());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	
	for (auto i : room) {
		if (pq.top() <= i.first) {
			pq.pop();
		}
		
		pq.push(i.second);
	}
	
	return pq.size();
}