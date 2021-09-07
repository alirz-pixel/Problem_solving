/*  2021-08-31  4:58
백준 1520번 내리막 길   ||  골드4
https://www.acmicpc.net/problem/1520



참고자료 - https://yabmoons.tistory.com/340

첫 시도 : BFS
두 번째 시도 : DFS + DP (하지만 시간초과)
세 번째 시도 : DFS + DP

알고리즘 기술 :
 - DP[][] = c는 ( m-1, n-1 )로 갈 수 있는 경로는 총 c개 존재한다는 의미이다.
 
 - (재귀함수) DFS로 순회하며, ( m-1, n-1 )에 도달한 경우
   이 경로에 포함된 DP 배열에 1[도착점으로 갈 수 있는 경로의 수]을 초기화 해준다.

   다른 경로들 또한 DFS로 순회하면서 dp 배열에 담긴 값을 확인하고,
   그 값을 이용하여 도착점으로 도달하는 경로의 수를 계속해서 구해나간다.




시작시간 : 2:57  
종료시간 : 4:21       걸린시간 : 1시간 24분  ||  제출횟수 : 4회
*/


#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<vector<int>> map, dp;
int m, n;

int DFS(int y, int x);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	cin >> m >> n;
	
	map = vector<vector<int>>(m, vector<int>(n));
	dp = vector<vector<int>>(m, vector<int>(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	
	// solve()
	cout << DFS(0, 0);

	return 0;
}


int DFS(int y, int x)
{
	// 도착점 도달
	if (y == m-1 && x == n-1)
		return 1;
	
	// 도착점에 갈 수 있는 경로 or 갈 수 없는 경로
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;	
	for (int i = 0; i < 4; i++)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		if (my < 0 || mx < 0 || mx >= n || my >= m)
			continue;

		if (map[y][x] > map[my][mx])
			dp[y][x] = dp[y][x] + DFS(my, mx);
	}

	return dp[y][x];
}