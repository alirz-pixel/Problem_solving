class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot_size = nums1.size() + nums2.size();
        int new_arr_size = tot_size / 2 + 1;
        
        vector<int> new_nums(new_arr_size);
        
        int top = 0, l = 0, r = 0;
        while(l < nums.size() && r < nums.size() && top < new_arr_size) {
            if (nums1[l] < nums2[r]) {
                new_nums[top++] = nums1[l++];
            }
            else {
                new_nums[top++] = nums2[r++];
            }
        }
        
        for (; l < nums1.size(); && top < new_arr_size l++) {
            new_nums[top++] = nums1[l];
        }
        
        for (; r < nums2.size(); && top < new_arr_size r++) {
            new_nums[top++] = nums2[r];
        }
        
        
        if (tot_size % 2) {
            return new_nums[new_arr_idx];
        }
        else {
            return (new_nums[new_arr_idx] + new_nums[new_arr_idx]) / 2;
        }
    }
};
