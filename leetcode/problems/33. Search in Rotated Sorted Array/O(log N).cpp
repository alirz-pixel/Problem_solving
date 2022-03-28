// 링크 : https://leetcode.com/problems/search-in-rotated-sorted-array/
// 시간복잡도 : O(log N)
// runtime : 0ms

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // 오른쪽이 정렬되어 있음.
            if (nums[mid] < nums[right]) {
                if (nums[right] >= target && nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
                    
            }
            // 왼쪽이 정렬되어 있음
            else {
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
};