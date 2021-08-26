/*
백준 14650 걷다보니 신천역 삼 || 실버1
https://www.acmicpc.net/problem/14650


backtracking 문제 : N과 M(2)
https://www.acmicpc.net/problem/15650

-------------------------------------------

backTracking 문제에서 풀었던 것처럼
알고리즘을 똑같이 작성하되, vector에 값을 따로 저장하지 않고
sum이라는 변수에 (0, 1, 2) 들을 더해간다.

그리고 (만약, 입력이 3자리수였다면) 함수를 3번 반복하였다면 [종료조건]
sum이 3으로 나누어 떨어지는지 확인한다.

(이유 : 3자리 자연수의 각 자리수를 더했을 때,
 3으로 나누어 떨어진다는 뜻은 3의 배수라는 뜻이기 때문이다.)

시작시간  5:10
종료시간  5:16    걸린시간 : 6분  ||  시도횟수 1회
*/



#include <iostream>

using namespace std;

int result = 0;

void backTracking(int n, int now, int sum);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n;
    cin >> n;

    backTracking(n, 1, 1);
    backTracking(n, 1, 2);

    cout << result;

    return 0;
}


void backTracking(int n, int now, int sum)
{
    if (n == now)
    {
        if (sum % 3 == 0)
            result++;

        return;
    }

    for (int i = 0; i <= 2; i++)
        backTracking(n, now + 1, sum + i);

    return ;
}
