/*  2022-01-14  23:55
백준 14719번 빗물 || 골드5
https://www.acmicpc.net/problem/14719


이 문제는 물이 고일만한 위치를 어떻게 파악하느냐가 중요한 문제라고 생각한다.

필자는 이 '물이 고일만한 위치'를 처음부터 탐색해가며
임시 변수를 하나를 선언하여 탐색하는 과정에서의 '최댓값'을 저장하고
2가지의 조건과 1가지의 예외 케이스로 나누어 풀이를 진행하였다.

[조건]
 1. 임시변수보다 현재 탐색중인 값이 작다면 
   -> 물이 고일만한 위치이다.
     => 그러므로 '임시변수의 값 - 현재 탐색중인 값'의 결과값을 totmp에 더해준다. 
        (tottmp : 임시변수에서 시작하여 물이 고일만한 위치가 실제로 물이 고였을 때의 값을 저장하는 변수)

 2. 임시변수보다 현재 탐색중인 값이 크거나 같다면
   -> 임시변수의 위치 ~ 현재 탐색중인 위치까지 고일 것이다.
     => 따라서 임시변수의 위치부터 현재까지 계산했던 tottmp를 total에다가 더해주고,
     => tottmp는 0으로 임시변수의 위치는 현재의 위치가 되도록 설정한다.


[예외케이스]
 위의 조건대로 처음부터 끝까지 탐색을 하는 과정에서 입력값들 중 '최종 최댓값'을 만나게 될 경우
 이 최댓값 이후에 대해선 고이는 빗물의 양을 구할 수 없다. (임시변수[최종 최댓값] 보다 크거나 같은 값이 더 이상 없으므로)
  -> 처음부터 끝까지 탐색만으론 고이는 빗물의 총량을 구할 수 없다.
    => 따라서 끝에서부터 '최종 최댓값'까지 탐색하는 과정을 한 번 더 해주면 된다.

시작시간 23:09
종료시간 23:35       걸린시간 : 26분  ||  시도횟수 : 1회
*/


#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    vector<int> block(w);
    for (auto &i : block)
        cin >> i;

    int tottmp = 0, total = 0, pointloc1 = 0;
    for (int i = 1; i < w; i++) {
        // 현재 기준점으로부터 같거나 큰 값 => 물이 고이지 않음 (그리고 기준점을 현재로 잡음)
        // 그리고 여태까지 쌓인 물을 다 더해줌
        if (block[pointloc1] <= block[i]) {
            pointloc1 = i;
            total += tottmp;
            tottmp = 0;
        }

        // 현재 기준점으로부터 작은 값 => '기준점 - 현재 탐색중인 블럭의 높이'만큼 물이 고임
        else {
            tottmp += (block[pointloc1] - block[i]);
        }        
    }

    tottmp = 0;
    int pointloc2 = w-1;
    for (int i = w-2; i >= 0; i--) {
        // 현재 기준점으로부터 같거나 큰 값 => 물이 고이지 않음 (그리고 기준점을 현재로 잡음)
        // 그리고 여태까지 쌓인 물을 다 더해줌
        if (block[pointloc2] <= block[i]) {
            pointloc2 = i;
            total += tottmp;
            tottmp = 0;
        }

        // 현재 기준점으로부터 작은 값 => '기준점 - 현재 탐색중인 블럭의 높이'만큼 물이 고임
        else {
            tottmp += (block[pointloc2] - block[i]);
        }        

        if (i == pointloc1)
            break;
    }

    cout << total;
}