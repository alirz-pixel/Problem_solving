// 걸린시간 : 15분

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<char> dummy(n * 2);
        
        backtracking(n ,n, 0, 2 * n, ans, dummy);
        
        return ans;
    }
    
    void backtracking(int open, int close, int index, int n, vector<string>& ans, vector<char>& dummy) {
        if (index == n) {
            if (open == 0 && close == 0) {
                string push_ans;
                
                for (auto i : dummy) {
                    push_ans += i;
                }
                
                ans.push_back(push_ans);
            }
            
            return;
        }
        
        // open '(' 추가
        if (open != 0) {
            dummy[index] = '(';
            backtracking(open - 1, close, index + 1, n, ans, dummy);
        }
        
        // close ')' 추가
        if (open < close) {
            dummy[index] = ')';
            backtracking(open, close - 1, index + 1, n, ans, dummy);
        }
        
        return;
    }
};