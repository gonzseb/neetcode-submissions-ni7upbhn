class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dictionary;

        for (string str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            dictionary[sorted_str].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& pair : dictionary) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
