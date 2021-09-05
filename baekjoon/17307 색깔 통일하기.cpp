/*  2021-08-31  4:58
백준 17307번 색깔 통일하기   ||  골드2
https://www.acmicpc.net/problem/17307


알고리즘 기술 :

붙어있는 공들에 대해 색깔을 몇번 바꿔야하는 지를 가중치로 두고 방향 그래프를 만든다.
그리고 이 가중치에 대해 구간합 알고리즘을 이용한 최단 경로를 구할 것이다.

우선 1번째부터 시작하여 n번째로 가는 가중치들을 모두 더한다.
(구간합 init)

그리고 2번째부터는 max('2->1'로 가는 최단경로, '2->n'으로 가는 최단경로)를 계속 계산하면서
이 값이 가장 작은 값을 출력으로 내보내면 된다.



시작시간 : 2:40
종료시간 : ?:??       걸린시간 : 대략 105분  ||  제출횟수 : 4회
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, k;
	cin >> n >> k;

	vector<int> button(n);
	for (auto& i : button)
		cin >> i;


	// solve();

	// first : 왼쪽, second : 오른쪽
	vector<pair<int, int>> graph(n);
	graph[n - 1].second = -1;

	graph[0].first = graph[n - 1].second = 0;
	// 그래프 세팅
	for (int i = 0; i < n - 1; i++)
	{
		int nextChange = button[i] - button[i + 1];
		if (nextChange > 0)
			nextChange = k - nextChange;
		else
			nextChange *= -1;


		graph[i].second = nextChange;
		graph[i + 1].first = (k - nextChange)%k;
	}

	// 구간 합 세팅
	long long temp[2] = { 0, };
	for (int i = 0; i < n; i++)
		temp[0] += graph[i].second;

	// 구간 합 solve()
	long long minIndex = 1, min = temp[0], now;
	for (int i = 1; i < n; i++)
	{
		temp[0] -= graph[i - 1].second;
		temp[1] += graph[i].first;

		now = max(temp[0], temp[1]);
		if (min > now)
		{
			min = now;
			minIndex = i+1;
		}
	}

	cout << minIndex << "\n" << min;
	return 0;
}