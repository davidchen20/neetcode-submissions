class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxLeft = height[left];
        int maxRight = height[right];

        int ans = 0;

        while (left < right) {
            if (maxLeft <= maxRight) {
                left++;
                ans += max(0, maxLeft - height[left]);

                maxLeft = max(maxLeft, height[left]);
            } else {
                right--;
                ans += max(0, maxRight - height[right]);

                maxRight = max(maxRight, height[right]);
            }
        }

        return ans;
    }
};
