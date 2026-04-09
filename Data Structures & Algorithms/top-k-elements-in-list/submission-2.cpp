class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return {};

        unordered_map<int, int> numsMap;

        for (int n : nums) {
            numsMap[n]++;
        }

        vector<int> topK;
        for (int i = 0; i < k; i++) {
            int n;
            int top = 0;


            for (const auto& pair : numsMap) {
                if (top < pair.second) {
                    n = pair.first;
                    top = pair.second;
                }
            }

            topK.push_back(n);
            numsMap.erase(n);
        }

        return topK;
    }
};
