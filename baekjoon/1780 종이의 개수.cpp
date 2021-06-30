/*
백준 1780번 종이의 개수 || 실버 2
https://www.acmicpc.net/problem/1780


재귀함수를 이용하여 '-1,  0, 1'로만 채워진 종이를 판별한다.

이런 분할 정복 문제를 풀 떄,
항상 막혔던 부분은 startX, startY, endX, endY를 정하는 부분에서 막혔었는데
이번엔 연산식을 구해, for문 이용하여 잘 풀었던 것 같아 뿌듯하다.

그리고 size가 3일 때, 재귀를 하여 쪼개는 것이 아닌 for문으로 이용하면
시간 복잡도 측면에서 이득을 볼 줄 알았지만, 큰 차이는 없었다


시작시간 : 3:49
종료시간 : 4:19
*/


#include <iostream>

using namespace std;

short int arr[2187][2187];
void cut(int* result, int startX, int startY, int endX, int endY);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);


    int N, result[3] = { 0, 0, 0 };
    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> arr[y][x];

    
    cut(result, 0, 0, N, N);


    for (int i = 0; i < 3; i++)
        cout << result[i] << "\n";
    return 0;
}

void cut(int* result, int startX, int startY, int endX, int endY)
{
    if (startX < 0 || startY < 0 || startX > endX || startY > endY)
        return;


    bool check = true;
    int size = endX - startX;

    for (int y = startY; y < endY; y++)
    {
        for (int x = startX; x < endX; x++)
            if (arr[y][x] != arr[startY][startX])
            {
                check = false;

                if (size == 3)
                {
                    cout << "size == 3";
                    break;
                }

                // 9개로 쪼개기
                int cut_X, cut_Y = startY, cut_Size = (size / 3);
                for (int i = 0; i < 3; i++)
                {
                    cut_X = startX;
                    for(int j = 0; j < 3; j++)
                    {
                        cut(result, cut_X, cut_Y, cut_X + cut_Size, cut_Y + cut_Size);
                        cut_X += cut_Size;
                    }

                    cut_Y += cut_Size;
                }

                break;
            }

        if (!check)
            break;
    }

    if (check)
        result[arr[startY][startX] + 1]++;

    else if (size == 3)
        for (int y = startY; y < endY; y++)
            for (int x = startX; x < endX; x++)
                result[arr[y][x] + 1]++;
}