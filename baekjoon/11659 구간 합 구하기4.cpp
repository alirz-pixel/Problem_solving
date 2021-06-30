/*
백준 11659번 구간 합 구하기 4 || 실버 3
https://www.acmicpc.net/problem/11659

좀 아쉽지만 혁수 형님께서 시간복잡도가 O(1)이 나온다고 알려주셔서
이 부분에 초점을 맞춰 풀었기 때문에 빠른 시간내에 정답을 맞춘 것 같아 아쉽다.



시작시간 : 9:58
종료시간 : 10:17   시도 횟수: 1  ||  소요시간: 19분
*/

  
  
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, M, t1, t2;
    cin >> N >> M;

    vector<int> input(N + 1);
    vector<int> sum(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> input[i];
        sum[i] = input[i] + sum[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> t1 >> t2;

        cout << sum[t2] - sum[t1 - 1] << "\n";
    }

    return 0;
}