#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        size_t lastSize = 0;
        for (int num : nums) {
            set.insert(num);
            if (set.size() == lastSize) return true;

            lastSize = set.size();
        }

        return false;
    }
};