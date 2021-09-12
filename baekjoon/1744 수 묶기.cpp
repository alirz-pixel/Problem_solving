/*  2021-09-12  1:31
백준 1744번 수 묶기  ||  골드4
https://www.acmicpc.net/problem/1744


틀렸습니다 1:
 - 처음에는 입력값을 정렬한 후에 앞에서부터 수를 체크하며
   { (맨 앞의 요소) * (그 뒤의 요소) = 양수 } 곱하고,
   { 아닐 경우 } 맨 앞의 요소를 더해가는 로직으로 짜게 되었다.

   틀린이유 :
     음수에 대해서 반례가 여럿 존재하여 (심지어 음수 곱하기의 최댓값은 내림차순으로 해야함.)
     틀리게 되었다.


틀렸습니다 2:
 - 양수/음수의 정렬을 다르게 해야 된다는 것을 깨닫고, 
   {negative, positive} 배열을 따로둬서 관리를 하여 풀었다.
   
   틀린이유 :
     양수의 곱셈에서 {맨 앞/그 뒤의 요소} 중 하나라도 1인 값이 있으면
     곱셈보다 덧셈이 더 크다는 것 때문에 틀리게 되었다.


틀렸습니다 3:
 - 위의 케이스들을 다 따로 처리하였으나, 결과는 이번에도 "틀렸습니다.."
   이번엔 도저히 못찾겠어서 질문 검색을 통해 틀린점이 무엇이었는지 확인하였다.

   틀린이유 :
    음수의 곱셈에서 양수값이 아닌 0인 값에 대해서도 고려할 필요가 있었다.
	(음수의 덧셈 < 0 이므로)
	 

시작시간 : 1:31
종료시간 : 1:50    제출시도 : 4회  ||  걸린시간 : 30분?
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n, temp;
	cin >> n;

	vector<int> positive, negative;
	while (n--)
	{
		cin >> temp;

		if (temp > 0)
			positive.push_back(temp);

		else
			negative.push_back(temp);
	}


	// solve();
	sort(positive.begin(), positive.end(), less<int>());
	sort(negative.begin(), negative.end(), greater<int>());

	int ans = 0, back;
	while (!positive.empty())
	{
		back = positive.back();
		positive.pop_back();

		if (positive.empty())
		{
			ans += back;
			break;
		}

		if (back != 1 && positive.back() != 1)
		{
			ans += (back * positive.back());
			positive.pop_back();
		}

		else
			ans += back;
	}

	while (!negative.empty())
	{
		back = negative.back();
		negative.pop_back();

		if (negative.empty())
		{
			ans += back;
			break;
		}

		if (back * negative.back() >= 0)
		{
			ans += (back * negative.back());
			negative.pop_back();
		}

		else
			ans += back;
	}

	cout << ans;
	return 0;
}