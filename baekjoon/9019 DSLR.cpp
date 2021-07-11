/*
백준 9019 DSLR || 골드 5
https://www.acmicpc.net/problem/9019


문제를 보자마자 BFS임을 알았지만 BFS의 결과를 출력할 방법을 생각하지 못했음..
인터넷 검색을 통하여 문제 전체에 대한 코드 말고 결과를 출력할 방법만 찾아봤음

 -> 큐에 스트링 넣을 생각을 전혀못함.. ㅋ;


하지만 스트링 복사나 쓰기 자체가 시간이 오래걸려
시간초과가 발생하였음.
이를 return을 잘 조정하여 해결하긴 했으나 찝찝하네;
*/


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 10000

using namespace std;

void BFS(int num, int end);
int operatorD(int num);  
int operatorS(int num);
int operatorL(int num);
int operatorR(int num);


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        BFS(a, b);
    }

    return 0;
}


void BFS(int num, int end)
{
    vector<bool> visited(MAX);
    queue<pair<int, vector<char>>> q;
    
    int topInt, tempInt;
    string topString;


    q.push({num, vector<char>(0)});
    visited[num] = true;
    while (!q.empty())
    {
        topInt = q.front().first;  
        topString = q.front().second;
        q.pop();



        // D 연산
        tempInt = operatorD(topInt);
        if (!visited[tempInt])
        {
            if (tempInt == end)
            {
                cout << topString + "D\n";
                return;
            }

            q.push({tempInt, topString + "D"});
            visited[tempInt] = true;
        }



        // S 연산
        tempInt = operatorS(topInt);
        if (!visited[tempInt])
        {
            if (tempInt == end)
            {
                cout << topString + "S\n"; 
                return ;
            }

            q.push({tempInt, topString + "S"});
            visited[tempInt] = true;    
        }



        // L 연산
        tempInt = operatorL(topInt);
        if (!visited[tempInt])
        {
            if (tempInt == end)
            {
                cout << topString + "L\n"; 
                return ;
            }

            q.push({tempInt, topString + "L"});
            visited[tempInt] = true;
        }



        // R 연산
        tempInt = operatorR(topInt);
        if (!visited[tempInt])
        {
            if (tempInt == end)
            {
                cout << topString + "R\n"; 
                return ;
            }

            q.push({tempInt, topString + "R"});
            visited[tempInt] = true;
        }
    }
}

int operatorD(int num)
{
    return (num * 2) % MAX;
}

int operatorS(int num)
{
    if (num == 0)
        return 9999;
    
    else
        return num - 1;
}

int operatorL(int num)
{
    return ((num / 1000) + ((num % 1000) * 10));
}

int operatorR(int num)
{
    return ((num / 10) + ((num % 10) * 1000));
}