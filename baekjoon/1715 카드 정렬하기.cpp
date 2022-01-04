/*
백준 1715 카드 정렬하기 || 골드4
https://www.acmicpc.net/problem/1715


참고 사이트 : 
https://yabmoons.tistory.com/414


문제에서 요구한 것처럼 오름차순으로 정렬한 후에
1번 + 2번 ->  '(1,2번 합한 것) + 3번' 의 규칙으로 진행하여 푸는 문제로 생각해버렸다.

그렇게 제출을 시도했다가 1번 틀리고,
반례들을 찾으러 갔으나 규칙이 보이지 않았다.

그래서 인터넷 검색을 하였더니 (1,2번 합한 것)을 또 새로운 카드 더미로 보고
(1,2번 합한 것)을 포함한 남은 카드 더미들 중 가장 작은 2더미를 더하는 것이
이번 문제의 킬포인트 였던 것이었다.

시작시간 4:00
종료시간 4:38    걸린시간 : 38분  ||  제출시도 : 2회


// ------- [ 재풀이 ] -----
시작시간  19:49
정료시간  19:55   걸린시간 : 6분  ||  제출시도 : 1회
*/



// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// void solve(priority_queue<int, vector<int>, greater<int>>& pq);
// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cout.tie(0);


//     priority_queue<int, vector<int>, greater<int>> pq;
//     int n, temp;
//     cin >> n;

//     for(int i = 0; i < n; i++)
//     {
//         cin >> temp;
//         pq.push(temp);
//     }

//     solve(pq);

//     return 0;
// }


// void solve(priority_queue<int, vector<int>, greater<int>>& pq)
// {
//     int card1, card2, temp = 0;
//     while(pq.size() != 1)
//     {
//         card1 = pq.top();   pq.pop();
//         card2 = pq.top();   pq.pop();

//         temp += (card1 + card2);

//         pq.push(card1 + card2);
//     }

//     cout << temp;
// }





// ----- [ 재풀이 ] -------
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, temp;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }    

    int result = 0;
    while (pq.size() != 1) {
        temp = pq.top();
        pq.pop(); // 제일 작은 카드 묶음 추출하기

        temp += pq.top();
        pq.pop();

        pq.push(temp);
        result += temp;
    }

    cout << result;

    return 0;
}