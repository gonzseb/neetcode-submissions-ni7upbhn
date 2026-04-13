class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;

        for (int i = 0; i < nums.size(); i++) {
            if (!nums_map.contains(nums[i])) {
                int reminder = target - nums[i];
                nums_map[reminder] = i;
            } else {
                return {nums_map[nums[i]], i};
            }
        }
        
        return {};
    }
};
