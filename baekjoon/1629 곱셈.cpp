/*
백준 1629 곱셈 || 실버 1
https://www.acmicpc.net/problem/1629



문제의 조건을 보고 시간복잡도가 O(N)인 알고리즘을 이용한 풀이는 불가능 할 것이라 판단이 되었으나
O(log n)을 이용한 알고리즘이 떠오르지 않아

알고리즘 분류를 누르게 되었으나, 알고리즘 분류가 '분할정복을 이용한 거듭제곱' 이란 소리르 보고
더 당황했던 것 같다. 

이 분류를 보고 5분 정도 추가적으로 고민했으나 도저히 떠오르지 않아
인터넷에 찾아보게 되었다.

인터넷에 나온 자료에서 코드는 보지 않고
공식만 활용하여 문제를 푸려고 하였으나
loop라는 함수를 들어가기 전에 expo가 홀수인지 짝수인지만 판단하여 풀었기 때문에
오답처리가 되었다...

즉, expo 가 6일 때, 첫 loop에서 6 / 2 = 3 이라는 점을 생각하지 못해
2번이나 틀리게 되었다.


시작시간 : 2:53
인터넷에 알고리즘을 찾은 시간 : 3:13
틀린 코드 제출 : 3:29
종료 시간 : 3:52           걸린 시간 : 1시간  ||  시도 횟수 3번
*/



#include <iostream>

using namespace std;

long long int loop(int num, int temp, int mod);
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int a, b, c;
    cin >> a >> b >> c;
    cout << loop(a, b, c);

    return 0;
}


long long int loop(int num, int expo, int mod)
{
    if (expo == 0)
        return 1;

    if (expo == 1)
        return num % mod;

    long long int temp = loop(num, expo / 2, mod);
    if (expo % 2 == 0)  return (temp * temp) % mod;

    // 홀수라면
    return (((num * temp) % mod) * temp) % mod;
}