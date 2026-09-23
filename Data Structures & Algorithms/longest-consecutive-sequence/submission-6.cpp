class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // no sorting
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i] - 1)) continue;
            int start = nums[i];
            int len = 1;
            while (s.count(start+1)) {
                len++;
                start++;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
