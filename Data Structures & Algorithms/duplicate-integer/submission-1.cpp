class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;

        for (int x : nums) {
            if (nums_set.count(x)) return true;
            nums_set.insert(x);
        }

        return false;
    }
};