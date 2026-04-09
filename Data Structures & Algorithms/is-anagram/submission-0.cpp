class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagramMap;

        for (char c : s) {
            anagramMap[c]++;
        }

        for (char c : t) {
            if (!anagramMap.count(c)) return false;
            anagramMap[c]--;
        }

        for (char c : s) {
            if (anagramMap[c] != 0) return false;
        }

        return true;
    }
};
