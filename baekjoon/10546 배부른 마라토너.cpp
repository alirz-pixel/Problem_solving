/*
백준 10546번 배부른 마라토너  || 실버 4
https://www.acmicpc.net/problem/10546

map을 연습하기 위해 이 문제를 선택하고 쉽게 풀고 제출했으나,
문제를 제대로 읽지않아 동명이인을 고려하지 못했다.
이를 고치는데 12분 소요

시작 : 1시 53분
종료 : 2시 12분
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main (void)
{
	map<string, pair<int, bool>> m;

	string temp;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (m[temp].second == true)
			m[temp].first++;
		
		else
			m[temp].second = true;
	}

	for (int i = 0; i < N - 1; i++)
	{
		cin >> temp;

		if (m[temp].first == 0)
			m[temp].second = false;

		else
			m[temp].first--;
	}
	map<string, pair<int, bool>>::iterator i_m = m[temp];

	for (auto itr = m.begin(); itr != m.end(); itr++)
		if (itr->second.second == true)
		{
			cout << itr->first;
			break;
		}
}