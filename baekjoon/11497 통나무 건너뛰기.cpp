/*  2021-09-14  13:07
백준 11497 통나무 건너뛰기  ||  실버1
https://www.acmicpc.net/problem/11497


알고리즘 기술 :
 - 우선 주어진 값을 오름차순으로 정렬한다. (배열 이름 : height)
   그리고 height의 n-1번째 값을 이용하여 초기 난이도를 설정한다. max(height[n-1] - height[n-2], height[n-1] - height[n-3]);

   이제 위에서 사용한 값을 제외한 나머지 값들을 이용하되,
   2개씩 짝지어서 1번째는 데큐의 맨 뒤,
                 2번째는 데큐의 맨 앞에 삽입하여 난이도를 책정한다.
				 
	모든 height의 값들을 데큐에 넣고 난 후에는 dq.back - dq.front 를 이용해서 마지막으로 난이도를 한번 더 책정한다.




시작시간 : 13:08 (+5분)
종료시간 : 13:28     제출시도 : 1회  ||  걸린시간 : 28분 + (5분)
*/



// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>

// using namespace std;

// int main(void)
// {
// 	cin.tie(0);
// 	ios::sync_with_stdio(false);


// 	int t, n;
// 	cin >> t;

// 	while (t--)
// 	{
// 		cin >> n;
// 		vector<int> height(n);

// 		for (auto &i : height)
// 			cin >> i;


// 		// solve();
// 		int result;

// 		sort(height.begin(), height.end(), less<int>());


// 		deque<int> dq;
// 		dq.push_back(height.back());
// 		height.pop_back();

// 		result = dq.back() - height.back();
// 		dq.push_back(height.back());
// 		height.pop_back();

// 		result = max(dq.front() - height.back(), result);
// 		dq.push_front(height.back());
// 		height.pop_back();


// 		while(!height.empty())
// 		{
// 			result = max(result, dq.back() - height.back());
// 			dq.push_back(height.back());
// 			height.pop_back();

// 			if (height.empty())
// 				break;

// 			result = max(result, dq.front() - height.back());
// 			dq.push_front(height.back());
// 			height.pop_back();
// 		}

// 		result = max(result, abs(dq.front() - dq.back()));
// 		cout << result << "\n";
// 	}

// 	return 0;
// }


// ------------------------------------------------------------
/*  2021-09-14  13:50


알고리즘 기술 : 
 - 전의 풀이처럼 어렵게 풀 필요 없이
   간단하게 내림차순으로 정렬하고 규칙을 찾으면, 쉽게 풀 수 있다.

   1. 주어진 값들을 내림차순으로 정렬한다.
   2. result 값에 max(height[0] - height[1], height[0] - height[2])을 저장한다.
   3. 그 후 1 ~ n-2까지 탐색하며, height[i] - height[i+2]을 확인해가며 최댓값을 갱신한다.
   4. 이렇게 탐색한 후에 최댓값(result)을 출력하면 된다.

시작시간 : 13:50
종료시간 : 14:00     제출시도 : 1회  ||  걸린시간 : 10분
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);


	int t, n;
	cin >> t;

	while (t--)
	{
		int result = 0;

		cin >> n;
		vector<int> height(n);

		for (auto &i : height)
			cin >> i;

		sort(height.begin(), height.end(), greater<int>());

		result = max(height[0] - height[1], height[0] - height[2]);
		for (int i = 1; i < n-2; i++)
			result = max(result, height[i] - height[i+2]);

		cout << result << "\n";
	}

	return 0;
}