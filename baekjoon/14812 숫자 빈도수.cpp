/*  2021-08-31  4:58
백준 14812번 숫자 빈도수   ||  실버5
https://www.acmicpc.net/problem/14812



... 시간복잡도를 잘 못 계산하여 시간이 터지는 줄 알고 오래걸리게 되었다.

알고리즘 기술 :
 - 주어진 n에 대하여 (1 ~ n) 까지의 d가 몇번 나오는지 새면된다. - (즉, 브루트포스.)

시작시간 : 12:09
종료시간 : 12:19       걸린시간 : 9분  ||  제출횟수 : 1회
*/


#include <iostream>

using namespace std;

void divide(int& result, int num, int& d);
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);


	int n, d;
	cin >> n >> d;


	// solve();
	int result = 0;
	for (int i = 1; i <= n; i++)
		divide(result, i, d);

	cout << result;

	return 0;
}


void divide(int& result, int num, int& d)
{
	while (num)
	{
		cout << num << "\n";
		if (num % 10 == d)
			result++;

		num /= 10;
	}
}