/*  2021-08-20  5:30
백준 22254번 공정 컨설턴트 호석 || 골드4
https://www.acmicpc.net/problem/22254


사용시간이 가장 적은 공정 라인에 배정  --> 우선순위 큐를 시간에 대해서 정렬되도록 작성
최소 공정라인의 수  --> 이분탐색을 이용하여 true면 더 작은 값이 가능한지, false면 더 큰값을 탐색 하도록 작성



시작시간 5:31
종료시간 5:45       걸린시간 : 14분  ||  시도횟수 : 2회 (+4회)
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool complete(vector<int>& line, int num, int x);
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);


    int n, x, result;
    cin >> n >> x;

    int left = 1, mid, right = n;
    vector<int> line(n);
    for (auto &i : line)
        cin >> i;


    while(left <= right)
    {
        mid = (left + right) / 2;

        if (complete(line, mid, x))
        {
            right = mid - 1;
            result = mid;
        }

        else
            left = mid + 1;
    }

    cout << result;
    return 0;
}


bool complete(vector<int>& line, int num, int x)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < num; i++)
        pq.push(line[i]);


    int top;
    for (int i = num; i < line.size(); i++)
    {
        top = pq.top() + line[i];
        pq.pop();

        if (top > x)
            return false;

        pq.push(top);
    }

    return true;
}