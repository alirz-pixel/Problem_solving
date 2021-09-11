/*  2021-09-12  12:9
백준 2156번 포도주 시식  ||  실버1
https://www.acmicpc.net/problem/2156



알고리즘 기술 :
 v % p = x
 (v / p) * l = y

 ans = x + y

 - 이런식으로 풀면 될 줄 알았으나,
   v % p 의 연산결과에서 L일을 넘어가버리는 반례가 존재하여
   오답처리가 되었다.


시작시간 : 12:10
종료시간 : 12:30     걸린시간 : 20분  ||  시도횟수 : 2회
*/


#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i = 0, ans, l, p, v, temp;
	while (++i)
	{
		cin >> l >> p >> v;
		if (!l && !p && !v)
			break;

		temp = v % p;
		if (l < temp)
			ans = l;
		else	
			ans = temp;

		ans += (v / p) * l;
		cout << "Case " << i << ": " << ans << "\n";
	}


	return 0;
}