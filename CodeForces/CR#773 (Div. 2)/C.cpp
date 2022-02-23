/*  2021-08-18  3:33
코드포스 Round #773 (Div. 2)  문제 : C
https://codeforces.com/contest/1642/problem/C

분야 : [??]


===========================================

overflow 이슈 -2...

풀이 :
 그리디를 살짝 접목시켜 최선의 값이 나오기 위해선
 input값이 작은 것을 기준으로 계산하는 것이 좋다.

 ex.
 1
 4 4
 1 16 4 4  의 입력에서 16먼저 처리하게 되면, 답이 0이 나오지 않음.

 따라서 정렬되어 있으면서 바로 찾을 수 있는 map을 이용하여 문제를 풀었다.

 map의 key값 * x에 대해서 frequency를 대조해본다.

 만약, key값에 해당하는 frequency의 값이 더 크다면 
 둘의 차만큼 '더 필요하게' 되는 것이며

 그렇지 않다면 둘의 차만큼 key값 * x의 frequency를 빼주면 된다.

=============================================


시작시간  19:41   
종료시간  20:22     걸린시간 : 41분  ||  제출시도 : 3회
*/



#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long t, n, x, input;
	cin >> t;

	long long sol;
	map<long long, long long> arr;
	while (t--) {
		cin >> n >> x;

		arr.clear();

		for (int i = 0; i < n; i++) {
			cin >> input;
			arr[input]++;
		}

		sol = 0;
		for (auto i : arr) {
			if (!arr[i.first]) {
				continue;
			}

			if (arr[i.first] <= arr[i.first * x]) {
				arr[i.first * x] -= arr[i.first];
			} else {
				sol += (arr[i.first] - arr[i.first * x]);
				arr[i.first * x] = 0;
			}
		}
		cout << sol << "\n";
	}
	return 0;
}