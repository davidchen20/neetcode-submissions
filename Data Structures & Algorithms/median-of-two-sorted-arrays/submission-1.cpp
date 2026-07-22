class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> bigger = nums1;
        vector<int> smaller = nums2;

        int totalSize = bigger.size() + smaller.size();

        if (bigger.size() < smaller.size()) {
            swap(bigger, smaller);
        }

        int left = 0;
        int right = smaller.size();

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (totalSize + 1) / 2 - i;

            int biggerLeft = j > 0 ? bigger[j - 1] : INT_MIN;
            int biggerRight = j < bigger.size() ? bigger[j] : INT_MAX;
            int smallerLeft = i > 0 ? smaller[i - 1] : INT_MIN;
            int smallerRight = i < smaller.size() ? smaller[i] : INT_MAX;

            if (biggerLeft <= smallerRight && biggerRight >= smallerLeft) {
                if (totalSize % 2 == 0) {
                    return (max(biggerLeft, smallerLeft) + min(biggerRight, smallerRight)) / 2.;
                } else {
                    return max(biggerLeft, smallerLeft);
                }
            } else if (smallerLeft > biggerRight) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return -1;
    }
};
