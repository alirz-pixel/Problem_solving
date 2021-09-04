/*  2021-09-04  11:47
백준 1170번 멀티탭 스케줄링   ||  골드1
https://www.acmicpc.net/problem/1170


알고리즘 기술 :

i) 뽑을 필요가 없다
 i-1] 이미 꼽혀있는 경우,
 i-2] 플러그가 비어있는 경우,

ii) 뽑아야만 하는 경우, 최선의 선택을 해야함
 ii-1] 앞으로 사용할 일이 없는 제품을 뽑아야함.
 ii-2] 앞으로 뽑을 제품들 중 가장 나중에 사용할 제품을 뽑아야 함.



시작시간 : 11:47  
종료시간 : ?:??       걸린시간 : 대략 105분  ||  제출횟수 : 2회
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, k, temp;
	cin >> n >> k;

	vector<int> product(k+1);
	vector<int> input(k);
	for (int i = 0; i < k; i++)
	{
		cin >> input[i];
		product[input[i]]++;
	}

	// solve()
	vector<bool> isUse(k+1);
	int cnt = 0, result = 0;
	bool isContinue;
	for (int i = 0; i < k; i++)
	{
		isContinue = false;
		product[input[i]]--;

		// 이미 사용 중
		if (isUse[input[i]] == true)
			continue;

		// 플러그가 비어있음
		if (cnt != n)
		{
			isUse[input[i]] = true;
			cnt++;
			continue;
		}

		// 뭔가 하나 빼야함

		result++;

		// 더 이상 사용하지 않을 제품
		for (int j = 1; j <= k; j++)
			if (isUse[j] && !product[j])
			{
				isContinue = true;
				isUse[j] = false;
				isUse[input[i]] = true;
				break;
			}

		if (isContinue)
			continue;


		// 이미 꽂혀있는 제품들 중 (앞으로) 사용할 제품들 중에 가장 마지막에 꼽히는 제품
		vector<int> lastpro(k+1);
		int maxIndex = 0;
		for (int j = i+1; j < k; j++)
			if (isUse[input[j]] && !lastpro[input[j]])
				lastpro[input[j]] = j;

		for (int j = 1; j <= k; j++)
			if (lastpro[j] > lastpro[maxIndex])
				maxIndex = j;

		isUse[maxIndex] = false;
		isUse[input[i]] = true;
	}

	cout << result;
	return 0;
}