/*  2022-02-15  12:29
백준 2980번 도로와 신호등  ||  실버4
https://www.acmicpc.net/problem/2980



시작시간 : 12:29
풀이구상 : 12:39

코드작성 : 12:42
종료시간 : 12:56     제출시도 : 1회  ||  걸린시간 : 27분
*/


#include <iostream>
#include <vector>

using namespace std;
using pipii = pair<int, pair<int, int>>;

int solve(vector<pipii>& traffic, int L);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int N, L;
	cin >> N >> L;
	
	vector<pipii> traffic(N);
	for (auto &i : traffic) {
		cin >> i.first >> i.second.first >> i.second.second;
	}
	
	cout << solve(traffic, L);
	
	return 0;
}

int solve(vector<pipii>& traffic, int L) {
	int cycle, previous = 0, goTime = 0;
	
	for (auto i : traffic) {
		goTime += i.first - previous;
		cycle = (i.second.first + i.second.second);
		
		if (goTime % cycle < i.second.first) {
			goTime += i.second.first - (goTime % cycle);
		}
		
		previous = i.first;
	}
	
	goTime += (L - traffic[traffic.size()-1].first);
	
	return goTime;
}