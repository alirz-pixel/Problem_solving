/*
백준 1931번 회의실 배정 || 실버 2
https://www.acmicpc.net/problem/1931

예상 알고리즘 분류 : 그리디 알고리즘
vector<pair<int, int>> 을 이용하여, sort한 후
BFS나 브루트포스 돌리면 될 듯 싶은데


결국 모르겠어서 정담을 찾아봤는데,
생각보다 너무 간단해서 열이 나기 시작함;;

내가 하려던 방식은 회의 시작시간을 정렬한 후에 추가적인 로직을 통해, 최대 회의수를 결정하는 것이었으나
https://jaimemin.tistory.com/391   || 여기서 찾은 자료로는 회의 종료시간을 정렬한 후에, 그 뒤에 가장 빨리오는 회의 시작 시간을 찾으며 최대 회의수를 찾으면
간단하게 풀 수 있었던 문제였음..

------------------------------------------------
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, begin, end, cnt = 1;
    cin >> N;

    vector<pair<int, int>> meet(N);
    for (int i = 0; i < N; i++)
        cin >> meet[i].second >> meet[i].first;

    sort(meet.begin(), meet.end()); //회의가 먼저 끝나는 시간으로 정렬


    end = meet[0].first; // 회의 한번 시작
    for (int i = 1; i < N; i++)
        if (end <= meet[i].second)
        {
            end = meet[i].first;
            cnt++;
        }
    
    cout << cnt;
    return 0;
}