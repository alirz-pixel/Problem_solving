// 링크 : https://leetcode.com/problems/search-in-rotated-sorted-array/
// 시간복잡도 : O(N)
// runtime : 4ms

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        
        return -1;
    }
};