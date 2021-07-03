/*
백준 10866번 덱 || 실버 4
https://www.acmicpc.net/problem/10866


덱과 string 객체를 선언한 후에 입력받는 대로 처리하면 될 듯


시작시간 : 3:37
종료시간 : 3:48
*/


#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    deque<int> DQ;
    int N, data;   string command;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "front")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
                cout << DQ.front() << "\n";
        }
        
        else if (command == "back")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
                cout << DQ.back() << "\n";
        }


        else if (command == "push_back")
        {
            cin >> data;
            DQ.push_back(data);
        }

        else if (command == "push_front")
        {
            cin >> data;
            DQ.push_front(data);
        }


        else if (command == "pop_front")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
            {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }

        else if (command == "pop_back")
        {
            if (DQ.empty())
                cout << "-1\n";

            else
            {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        

        else if (command == "empty")
        {
            if (DQ.empty())
                cout << "1\n";

            else
                cout << "0\n";
        }

        else if (command == "size")
            cout << DQ.size() << "\n";

    }

    return 0;
}