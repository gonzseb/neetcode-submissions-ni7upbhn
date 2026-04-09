class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        int i = 0;

        while (i < nums.size() - 1) {
            int j = i + 1;

            while (j < nums.size()) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i); ans.push_back(j);
                    break;
                } else {
                    j++;
                }
            }
            i++;
        }

        return ans;
    }
};
