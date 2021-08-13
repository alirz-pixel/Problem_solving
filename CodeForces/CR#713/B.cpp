#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        bool allInput = false, end = false;
        pair<int, int> coord[2];
        int length[2];

        cin >> n;

        vector<string> input(n);
        for (int j = 0; j < n; j++)
            cin >> input[j];


        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
                if (input[y][x] == '*')
                {
                    if (!allInput)
                    {
                        coord[0].first = x;
                        coord[0].second = y;

                        allInput = true;
                    }

                    else
                    {
                        coord[1].first = x;
                        coord[1].second = y;

                        end = true;
                        break;
                    }
                }

            if (end)
                break;
        }

        length[0] = abs(coord[0].first - coord[1].first);
        length[1] = abs(coord[0].second - coord[1].second);

        if (coord[0].second == coord[1].second)
        {
            if (coord[0].second + 1 < n)
            {
                input[coord[0].second + 1][coord[0].first] = '*';
                input[coord[1].second + 1][coord[1].first] = '*';
            }

            else
            {
                input[coord[0].second - 1][coord[0].first] = '*';
                input[coord[1].second - 1][coord[1].first] = '*';
            }
        }

        else if (coord[0].first == coord[1].first)
        {
            if (coord[0].first + 1 < n)
            {
                input[coord[0].second][coord[0].first + 1] = '*';
                input[coord[1].second][coord[1].first + 1] = '*';
            }

            else
            {
                input[coord[0].second][coord[0].first - 1] = '*';
                input[coord[1].second][coord[1].first - 1] = '*';
            }
        }

        else if (coord[0].first > coord[1].first)
        {
            if (length[0] < length[1])
            {
                input[coord[0].second][coord[0].first - length[0]] = '*';
                input[coord[1].second][coord[1].first + length[0]] = '*';
            }

            else
            {
                input[coord[0].second + length[1]][coord[0].first] = '*';
                input[coord[1].second - length[1]][coord[1].first] = '*';
            }
        }

        else if (coord[0].first < coord[1].first)
        {
            if (length[0] < length[1])
            {
                input[coord[0].second][coord[0].first + length[0]] = '*';
                input[coord[1].second][coord[1].first - length[0]] = '*';
            }

            else
            {
                input[coord[0].second + length[1]][coord[0].first] = '*';
                input[coord[1].second - length[1]][coord[1].first] = '*';
            }
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
                cout << input[y][x];
            cout << "\n";
        }
    }
    return 0;
}