/*
백준 7662번 이중 우선순위 큐   || 골드 5
https://www.acmicpc.net/problem/7662

(처음에는 우선순위 큐를 MAX HEAP, MIN HEAP 두개를 선언해서 사용했으나)
(중간에 삭제가 일어나고, 다시 삽입이 일어날 때를 생각하지 못해서 틀림)


그 후, 어떤 자료구조를 사용해야할 지 몰라서 인터넷 검색을 통해 알게되었음
  중복값이 허용이 되는 multiset을 이용하였고, 
  최댓값 삭제는 --Se.end()
  최솟값 삭제는 Se.begin()

시작 시간: 2:50
종료 시간: 4:15  ||  총 시도 횟수 : 2회, 걸린 시간 1시간 25분
*/

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int T, k;    char oper;   long long int n;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        multiset<long long int> Se;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> oper >> n;
            
            if (oper == 'I')
                Se.insert(n);

            else if (Se.size() != 0)
            {
                if (n == 1) // max 삭제
                    Se.erase(--Se.end());

                else
                    Se.erase(Se.begin());
            }
        }

        if (Se.size() == 0)
            cout << "EMPTY\n";

        else
        {
            cout << *(--Se.end()) << " ";
            cout << *(Se.begin()) << "\n";
        }
    }

    return 0;
}


/*
for (int i = 0; i < 5; i++)
    {
        pq_MAX.push(i);
        pq_MIN.push(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << pq_MAX.top() << " ";
        pq_MAX.pop();
    }

    cout << endl;
    
    for (int i = 0; i < 5; i++)
    {
        priority_queue<int, vector<int>, greater<int>> pq_MIN;
        if (pq_MIN.empty())
            cout << "empty!" << " ";
        else
            cout << pq_MIN.top() << " ";
        pq_MIN.pop();
    }
*/