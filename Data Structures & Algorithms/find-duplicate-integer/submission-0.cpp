class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;

        for (int num : nums) {
            if (nums_set.contains(num)) {
                return num;
            }
            nums_set.insert(num);
        }
    }
};
