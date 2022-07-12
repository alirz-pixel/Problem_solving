#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_target(int depth, const vector<int>& numbers, int target, int cur_sum) {
    if (depth == numbers.size()) {
        if (cur_sum == target) {
            return 1;
        }
        
        return 0;
    }
    
    int ret = 0;
    ret += find_target(depth + 1, numbers, target, cur_sum + numbers[depth]);
    ret += find_target(depth + 1, numbers, target, cur_sum - numbers[depth]);
        
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = find_target(0, numbers, target, 0);
    return answer;
}
