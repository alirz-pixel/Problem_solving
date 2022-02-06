/*  2021-09-30  14:52
프로그래머스 
로또의 최고 순위와 최저 순위  ||  level 1.
https://programmers.co.kr/learn/courses/30/lessons/77484#fn1



이 문제는 알아볼 수 없는 수를 어떻게 이용할 것인가가 중요한 문제라고 생각한다.

[문제 풀이]
 1. 당첨번호와 (0을 제외한)구매한 로또 번호를 토대로 최저 순위를 게산한다.
   ==> map 사용

 2. 최저 순위에 0의 갯수를 더하여 최고 순위를 계산한다.
   ==> lottos 배열에 0이 몇 개 있는지 탐색



시작시간 : 14:52
종료시간 : 15:13     제출시도 : 1회  ||  걸린시간 : 21분
*/


#include <string>
#include <vector>
#include <map>

using namespace std;

int rank_calc(int cnt) { // cnt == 맞춘 갯수
    if (cnt < 2)  // 1개 이하를 맞춘 경우,
        return 6; // 6등

    return 7-cnt; // 나머지의 경우, (7 - 맞춘 갯수)등
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // win_cnt == 맞춘 갯수, zero_cnt == 0의 갯수
    int win_cnt = 0, zero_cnt = 0; 
    
    
    map<int, bool> win_temp;
    for (auto i : win_nums) {
        win_temp[i] = true; // map에 당첨 번호 저장하기
    }
    
    for (auto i : lottos) {
        if (win_temp[i]) { // 위에서 저장한 map을 토대로 맞춘 갯수 계산
            win_cnt++;            
        } else if (i == 0) { // i가 0이라면 알아볼 수 없는 번호
            zero_cnt++;
        }
    }
    
    vector<int> answer;
    answer.push_back(rank_calc(zero_cnt + win_cnt));
    answer.push_back(rank_calc(win_cnt));
    return answer;
}