#include <iostream>

using namespace std;

int cut(string arr[64], int W_Start, int W_End, int H_Start, int H_End);

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N;
    string arr[64];
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cut(arr, 0, N, 0, N);

    return 0;
}

int cut(string arr[64], int W_Start, int W_End, int H_Start, int H_End)
{
    int length = W_End - W_Start;

    bool error = false;
    char first = arr[H_Start][W_Start];

    if (length == 0)
        return 0;

    if (length == 1)
    {
        if (first == '0')
            cout << '0';
        else
            cout << '1';

        return 0;
    }

    for (int i = H_Start; i < H_End; i++)
    {
        for (int j = W_Start; j < W_End; j++)
            if (arr[i][j] != first)
            {
                error = true;
                break;
            }

        if (error)
            break;
    }

    if (error)
    {
        cout << '(';
        cut(arr, W_Start, W_Start + (length / 2), H_Start, H_Start + (length / 2));
        cut(arr,  W_Start + (length / 2),   W_End, H_Start, H_Start + (length / 2));
        cut(arr, W_Start, W_Start + (length / 2), H_Start + (length / 2), H_End);
        cut(arr, W_Start + (length / 2),   W_End, H_Start + (length / 2), H_End);
        cout << ')';
    }

    else
    {
        if (first == '0')
            cout << "0";
        else
            cout << "1";
    }

    return 0;
}