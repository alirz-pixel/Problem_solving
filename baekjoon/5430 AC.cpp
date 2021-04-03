#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    bool reverse, ERROR;
    int T, n;
    string command, array_temp, toInt = "";

    cin >> T;

    for (int i = 0; i < T; i++) // MAX_T = 100
    {
        deque<int> array;
        reverse = false; ERROR = false;

        cin >> command;
        cin >> n;               // MAX_n = 100,000
        cin >> array_temp;

        for (int j = 1; array_temp[j] != '\0'; j++)
        {
            if (array_temp[j] == ',' || (array_temp[j] == ']' && j != 1))
            {
                array.push_back(stoi(toInt));
                toInt = "";
            }

            else
                toInt += array_temp[j];
        }

        for (int k = 0; command[k] != '\0'; k++)
        {
            if (command[k] == 'R')
            {
                if (reverse)
                    reverse = false;

                else
                    reverse = true;
            }

            else // arrry[k]가 D인 경우
            {
                if (array.empty()) //array 가 비었다면
                {
                    cout << "error\n";
                    ERROR = true;
                    break;
                }

                else
                {
                    if (!reverse)
                        array.pop_front();

                    else
                        array.pop_back();
                }
            }
        }

        if (!ERROR)
        {
            int size = (int)array.size();

            cout << "[";

            if (reverse && size != 0)
            {
                for (int j = size - 1; j >= 1; j--)
                    cout << array[j] << ",";
                cout << array[0];
            }

            else if (!reverse && size != 0)
            {
                for (int j = 0; j < size-1; j++)
                    cout << array[j] << ",";
                cout << array[size-1];
            }
            cout << "]\n";
        }
    }
}