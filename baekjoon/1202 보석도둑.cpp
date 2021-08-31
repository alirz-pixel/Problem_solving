/*  2021-09-01  8:15
백준 1202번 최소 스패닝 트리  ||  골드4
https://www.acmicpc.net/problem/1202




step 1. 보석의 정보들을 보석의 무게를 기준으로 오름차순 정렬한다.
        (우선순위 큐에 저장)
step 2. 가방에 담을 수 있는 최대 무게를 오름차순으로 정렬한다.

step 3. 현재 가방의 최대 담을 수 있는 보석의 무게를 넘지 않는 한에서 
        (보석정보)우선순위 큐의 내용을 하나씩 빼면서 새로운 우선순위 큐에 저장한다.
step 4. (3)의 과정이 끝난 후, 가장 비싼 보석이 담기도록 새로운 우선순위 큐에서 요소 하나 뺀 후에 result에 넣어준다.


시작시간 : 8:17
종료시간 : 8:40       걸린시간 : 23분  ||  제출횟수 : 2회
*/


#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void solve(vector<int>& bag, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq_dia);
int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.tie(0);


  int n, k;
  cin >> n >> k;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_dia;
  pair<int, int> input_dia;
  for (int i = 0; i < n; i++)
  {
    cin >> input_dia.first >> input_dia.second;
    pq_dia.push(input_dia);
  }

  vector<int> bag(k);
  for (int i = 0; i < k; i++)
    cin >> bag[i];

  sort(bag.begin(), bag.end());

  solve(bag, pq_dia);

  return 0;
}


void solve(vector<int>& bag, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq_dia)
{
  priority_queue<int> pq;
  long long result = 0;

  for (auto i : bag)
  {
    while(!pq_dia.empty())
    {
      if (pq_dia.top().first > i)
        break;
      pq.push(pq_dia.top().second);
      pq_dia.pop();
    }

    if (pq.empty())
      continue;

    result += pq.top();
    pq.pop();
  }

  cout << result;
}