#include <iostream>

using namespace std;

int cut(char arr[][128], int& white, int& blue, int W_Start, int W_End, int H_Start, int H_End);

int main (void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, white = 0, blue = 0;
    char arr[128][128];
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    cut(arr, white, blue, 0, N, 0, N);

    cout << white << "\n" << blue;

    return 0;
}

int cut(char arr[][128], int& white, int& blue, int W_Start, int W_End, int H_Start, int H_End)
{
    int length = W_End - W_Start;

    bool error = false;
    char first = arr[H_Start][W_Start];

    if (length == 0)
        return 0;

    if (length == 1)
    {
        if (first == '0')
            white++;
        else
            blue++;

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
        cut(arr, white, blue, W_Start, W_Start + (length / 2), H_Start, H_Start + (length / 2));
        cut(arr, white, blue, W_Start + (length / 2),   W_End, H_Start, H_Start + (length / 2));
        cut(arr, white, blue, W_Start, W_Start + (length / 2), H_Start + (length / 2), H_End);
        cut(arr, white, blue, W_Start + (length / 2),   W_End, H_Start + (length / 2), H_End);
    }

    else
    {
        if (first == '0')
            white++;
        else
            blue++;
    }

    return 0;
}