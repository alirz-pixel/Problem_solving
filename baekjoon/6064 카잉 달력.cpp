/*  2021-09-09  9:58
백준 6064번 카잉 달력  ||  실버1
https://www.acmicpc.net/problem/6064



각각의 x, y 값은 모듈로 연산을 통해 계산된 값이거나 본연의 값일 것이다.
따라서 몇번 쨰 해인지를 계산하기 위해 모듈로 연산을 반대로 수행해보면서 확인하면 된다.

즉, M = 10 | N = 12 | x = 3 | y = 1 이라면
(모듈로 연산 전)x의 값 후보는 3, 13, 23, ... 이 될 것이고
(모듈로 연산 전)y의 값 후보는 1, 13, 25, ... 이 될 것이다.

이러한 값 후보들을 적었을 때, 
x와 y가 '일치하는' 값이 존재한다면 그것이 정답이다.


다만, 주의해야할 점이 존재하는데
그것은 바로 '마지막 해'이다.

카잉 달력의 마지막 해를 <10, 12>라고 한다면 60번째의 값이 된다.
즉, 마지막 해가 <M, N> 이라면 M, N의 최소공배수가 마지막 해의 번째가 되는 것이다.



시작시간 : 10:05
종료시간 : 10:24     제출시도 : 1회  ||  걸린시간 : 26분 (19분)
*/


// 10:05
#include <iostream>

using namespace std;

int gcd(int a, int b);
int solve(int M, int N, int x, int y);
int lcm(int a, int b);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int T;
	cin >> T;

	int M, N, x, y;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		cout << solve(M, N, x, y) << "\n";
	}


	return 0;
}

int gcd(int a, int b) { // 최대공약수
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b) { // 최소공배수
	return a * b / gcd(a, b);
}

int solve(int M, int N, int x, int y) {

	// -1의 조건 M, N의 최소공배수를 넘김
	int _lcm = lcm(M, N); // M, N의 최소공배수 구하기

	while (!(x > _lcm && y > _lcm)) {
		if (x == y)
			return x;

		if (x < y) {
			x += M;
		} else {
			y += N;
		}
	}

	return -1;
}