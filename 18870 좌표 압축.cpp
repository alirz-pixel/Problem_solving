#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Coord {
    int X;
    int rank;
    int index;
};

bool x_Cmp(Coord a, Coord b)
{
    return a.X < b.X;
}

bool index_Cmp(Coord a, Coord b)
{
    return a.index < b.index;
}


int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, rank_Temp = 0;
    cin >> N;

    vector<Coord> coord(N);
    for (int i = 0; i < N; i++)
    {
        coord[i].index = i;

        cin >> coord[i].X;
    }

    sort(coord.begin(), coord.end(), x_Cmp);

    for (int i = 0; i < N - 1; i++)
    {
        coord[i].rank = rank_Temp;

        if (coord[i].X < coord[i + 1].X)
            rank_Temp++;
    }
    coord[N - 1].rank = rank_Temp;

    sort(coord.begin(), coord.end(), index_Cmp);
    
    for (int i = 0; i < N; i++)
        cout << coord[i].rank << " ";

    return 0;
}