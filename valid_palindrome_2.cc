class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s.at(i) != s.at(s.size() - 1 - i)) {
                int j = s.size() - 1 - i;
                return (IsValidPalindrome(s, i, j - 1) ||
                        IsValidPalindrome(s, i + 1, j));
            }
        }
        return true;
    }
private:
    bool IsValidPalindrome(string s, int left, int right) {
        while (left < right)
            if (s.at(left++) != s.at(right--))
                return false;
        return true;
    }
};
