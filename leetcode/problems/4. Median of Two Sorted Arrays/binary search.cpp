class Solution {
public:
    double find_num(vector<int>& nums1, vector<int>& nums2, int mid_idx) {
        bool is_find_mid_loc = false;
        

        int l = 0, r = nums2.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int upper_idx = upper_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin() + mid + 1;
            int lower_idx = lower_bound(nums1.begin(), nums1.end(), nums2[mid]) - nums1.begin() + mid + 1;
            
            
            if (lower_idx <= mid_idx && mid_idx <= upper_idx) {
                return nums2[mid];
            }
            
            
            if (upper_idx < mid_idx) {
                l = mid + 1;    
            }
            else {
                r = mid - 1;
            }
        }
        
        
        l = 0, r = nums1.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int upper_idx = upper_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin() + mid + 1;
            int lower_idx = lower_bound(nums2.begin(), nums2.end(), nums1[mid]) - nums2.begin() + mid + 1;


            if (lower_idx <= mid_idx && mid_idx <= upper_idx) {
                return nums1[mid];
            }

            if (upper_idx < mid_idx) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot_size = nums1.size() + nums2.size();
        int mid_idx = (tot_size + 1) / 2;
    
        
        if (tot_size % 2) {
            return find_num(nums1, nums2, mid_idx);
        }
        else {
            return (find_num(nums1, nums2, mid_idx) + find_num(nums1, nums2, mid_idx + 1)) / 2;
        }
        return 1;
    }
};
