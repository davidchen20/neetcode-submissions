class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) swap(nums1, nums2);

        int totalLen = nums1.size() + nums2.size();
    
        int left = 0;
        // need exclusive bounds in order to account for case where we take no numbers from nums1 to put in left
        int right = nums1.size();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // exclusive bound
            int nums2LeftEndIndex = (totalLen + 1) / 2 - mid;

            int nums1LeftEnd = mid - 1 >= 0 ? nums1[mid - 1] : INT_MIN;
            int nums2LeftEnd = nums2LeftEndIndex - 1 >= 0 ? nums2[nums2LeftEndIndex - 1] : INT_MIN;
            int nums1RightStart = mid < nums1.size() ? nums1[mid] : INT_MAX;
            int nums2RightStart = nums2LeftEndIndex < nums2.size() ? nums2[nums2LeftEndIndex] : INT_MAX;

            if (nums1RightStart < nums2LeftEnd) {
                left = mid + 1;
            } else if (nums1LeftEnd > nums2RightStart) {
                right = mid - 1;
            } else {
                if (totalLen % 2 == 0) {
                    return (max(nums1LeftEnd, nums2LeftEnd) + min (nums1RightStart, nums2RightStart)) / 2.;
                } else {
                    return max(nums1LeftEnd, nums2LeftEnd);
                }
            }
        }

        return 0;
    
    }
};
