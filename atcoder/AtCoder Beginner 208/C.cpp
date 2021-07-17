/*
https://atcoder.jp/contests/abc208/tasks/abc208_c
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
	

	long long int N, K;
    cin >> N >> K;

    vector<long long int> human(N); // 가지고 있는 수 
    vector<pair<int, int>> human_NUM(N); // 두번째는 인덱스를 다룰 것임
    for (int i = 0; i < N; i++)
    {
        human[i] = K / N;

        cin >> human_NUM[i].first;
        human_NUM[i].second = i;
    }
    K %= N;

    sort(human_NUM.begin(), human_NUM.end());
    
    for (int i = 0; i < K; i++)
        human[human_NUM[i].second]++;

    
    for (int i = 0; i < N; i++)
        cout << human[i] << "\n";

	return 0;
}
