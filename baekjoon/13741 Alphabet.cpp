/*  2021-08-31  4:58
백준 13741번 Alphabet   ||  실버1
https://www.acmicpc.net/problem/13741




a~z가 되도록 하는 문자열을 만들어야 한다.
여기서 입력 중 삭제 해야되는 갯수는 중요하지 않으므로
추가해야 하는 알파벳의 수를 LIS를 이용하여 구할 수 있다.
((a~z) 사이에 이상한 게 껴있다면 무시해도 상관없단 뜻)

LIS 알고리즘을 이용하여 최대 가장 긴 증가하는 부분수열을 구했다면,
이제 알파벳의 갯수인 26 - max_LIS를 해주면 된다.


시작시간 : 11:45
종료시간 : 11:55       걸린시간 : 10분  ||  제출횟수 : 1회
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	string input;
	cin >> input;

	// solve();
	vector<int> dp(input.size(), 0);
	int result = 0, LIS_Max;

	for (int i = 0; i < input.size(); i++)
	{
		LIS_Max = 0;
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
				LIS_Max = max(LIS_Max, dp[j]);
		}

		dp[i] = LIS_Max + 1;

		if (dp[i] > result)
			result = dp[i];
	}

	cout << 26-result;
	return 0;
}