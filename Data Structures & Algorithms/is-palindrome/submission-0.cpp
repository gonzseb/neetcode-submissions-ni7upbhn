class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            // skip non-alphanumeric from the left
            while (i < j && !isalnum(s[i])) i++;

            // skip non-alphanumeric from the right
            while (i < j && !isalnum(s[j])) j--;

            // compare lowercase versions
            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};
