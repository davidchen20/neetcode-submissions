class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (auto num : nums) {
            s.insert(num);
        }

        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            // if theres a val one smaller, that means we are currently in the middle and should skip until we find it
            if (s.count(val-1)) continue;
            int count = 0;
            while(s.count(val)) {
                count++;
                val++;
            }

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};
