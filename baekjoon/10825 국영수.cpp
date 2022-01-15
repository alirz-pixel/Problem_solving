/*
백준 10825번 국영수 || 실버 4
https://www.acmicpc.net/problem/10825


항상 compare 함수를 작성하는 부분에서 막혔었는데 잘 적어둔 블로그 덕분에
빠르게 익힐 수 있었고, 앞으로도 외울 수 있을 것 같다.

compare 함수의 '<'는 음악의 기호처럼 뒤에가 점점 커진다라는 생각으로 코드를 작성하면 편하고
               '>'는 반대로 뒤에가 점점 작아진다라는 생각으로 코드를 작성하면 된다.


[참고 사이트] :
 - https://urbangy.tistory.com/43
 - https://artbooks.tistory.com/42
 - https://leeeegun.tistory.com/5


시작시간 : 9:37  
종료시간 : 10:01     걸린시간 : 24분  |  시도횟수 1회
*/

  
  
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct _score {
    int korean;
    int english;
    int math;
    string name;
} score;

bool compare(const score& x, const score& y);
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);


    int n;
    cin >> n;

    vector<score> input(n);
    for (auto &i : input) {
        cin >> i.name >> i.korean >> i.english >> i.math;
    }   

    sort(input.begin(), input.end(), compare);

    for (auto i : input) {
        cout << i.name << "\n";
    }

    return 0;
}

bool compare(const score& x, const score& y) {
    // 반환값이 true면 왼쪽이 오른쪽보다 작다고 생각한다.
    if (x.korean == y.korean) {
        if (x.english == y.english) {
            if (x.math == y.math) {
                return x.name < y.name;
            } 
            return x.math > y.math;
        }
        return x.english < y.english;
    }
    return x.korean > y.korean;
}