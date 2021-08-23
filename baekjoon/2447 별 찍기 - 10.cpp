/*  2021-08-22  8:36
백준 2447번 별 찍기 - 10 || 실버1
https://www.acmicpc.net/problem/2



정석적인 분할정복법으로 풀었으나,
오랜만에 이 분류를 풀었는지라 코드를 좀 더럽게 푼 점이 아쉽다..


시작시간 : 6:29
종료시간 : 6:59     걸린시간 : 대략 30분  ||  제출횟수 : 1회
*/



#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> output;

void divide(int n, int x, int y, int size);
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	output = vector<vector<char>>(n, vector<char>(n));

	// 쪼개기 시작

	divide(n, 0, 0, n);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << output[y][x];
		cout << "\n";
	}
	return 0;
}


void divide(int n, int x, int y, int size)
{
	if (size == 0)
		return;

	if (size == 3)
	{
		for (int tmpY = y; tmpY < y + size; tmpY++)
			for (int tmpX = x; tmpX < x + size; tmpX++)
				output[tmpY][tmpX] = '*';

		// 가운데 빈 공간 생성하기
		output[y + 1][x + 1] = ' ';

		return;
	}

	// 사이즈가 3이 아니라면
	// 9 분할정복 시작
	divide(n, x, y, size / 3);
	divide(n, x + (size / 3), y, (size / 3));
	divide(n, x + ((size / 3) * 2), y, (size / 3));


	divide(n, x, y + (size / 3), (size / 3));
	// 가운데 빈 공간 채우기
	for (int i = y+(size/3); i < (y+(size/3)) + (size / 3); i++)
		for (int j = x+(size/3); j < (x+(size/3)) + (size / 3); j++)
			output[i][j] = ' ';
	divide(n, x + ((size / 3) * 2), y + (size / 3), (size / 3));


	divide(n, x, y + ((size / 3) * 2), (size / 3));
	divide(n, x + (size / 3), y + ((size / 3) * 2), (size / 3));
	divide(n, x + ((size / 3) * 2), y + ((size / 3) * 2), (size / 3));

	return;
}