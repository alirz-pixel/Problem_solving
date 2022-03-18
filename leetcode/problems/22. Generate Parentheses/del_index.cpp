// 걸린시간 : 15분

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        
        backtracking(n, n, ans, curr);
        
        return ans;
    }
    
    void backtracking(int open, int close, vector<string>& ans, string& curr) {
        if (close == 0) {
            ans.push_back(curr);
            
            return;
        }
        
        // open '(' 추가
        if (open != 0) {
            curr.push_back('(');
            backtracking(open - 1, close, ans, curr);
            curr.pop_back();
        }
        
        // close ')' 추가
        if (open < close) {
            curr.push_back(')');
            backtracking(open, close - 1, ans, curr);
            curr.pop_back();
        }
        
        return;
    }
};