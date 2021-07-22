/*
백준 7662 이중 우선순위 큐 || 골드 5
https://www.acmicpc.net/problem/17626






시작시간 : 3:20
종료시간 : 
*/



#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    multiset<long long int> ms;
    long long int temp;
    char command;
    int t, k;     

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ms.clear();

        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> command >> temp;

            if (command == 'I')
                ms.insert(temp);

            else
            {
                if (ms.size() == 0)
                    continue;

                if (temp == -1)
                    ms.erase(ms.begin());

                else
                    ms.erase(--ms.end());
            }
        }

        if (ms.size() == 0)
            cout << "EMPTY\n";
        else
            cout << *(--ms.end()) << " " << *ms.begin() << "\n";
    }

    // ms.insert(2);
    // ms.insert(2);
    // ms.insert(4);
    // ms.insert(3);
    // ms.insert(7);

    // ms.erase(ms.begin());
    // ms.erase(--ms.end());
    // cout << *ms.begin() << " " << *(--ms.end()) << "\n";

    // for (auto& i : ms)
    //     cout << i << "\n";

    return 0;
}