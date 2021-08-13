#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int h, w, n;
    cin >> h >> w >> n;

    vector<pair<int, int>> graph1(n);
    vector<pair<int, int>> graph2(n);
    vector<pair<int, int>> result(n);
    for (int i = 0; i < n; i++)
    {
        cin >> graph1[i].first >> graph2[i].first;
        graph1[i].second = graph2[i].second = i; // i = index;
    }

    if (n == 1)
    {
        cout << "1 1";
        return 0;
    }

    sort(graph1.begin(), graph1.end());
    sort(graph2.begin(), graph2.end());

    // graph1 == 행,  graph2 == 열
    int temp1, temp2, rank1 = 1, rank2 = 1;
    temp1 = graph1[0].first;
    result[graph1[0].second].first = rank1;

    temp2 = graph2[0].first;
    result[graph2[0].second].second = rank2;

    for (int i = 1; i < n; i++)
    {   
        if (temp1 != graph1[i].first)
        {
            temp1 = graph1[i].first;
            rank1++;
        }


        if (temp2 != graph2[i].first)
        {
            temp2 = graph2[i].first;
            rank2++;
        }

        result[graph1[i].second].first = rank1;
        result[graph2[i].second].second = rank2;
    }

    for (int i = 0; i < n; i++)
        cout << result[i].first << " " << result[i].second << "\n";
    return 0;
}