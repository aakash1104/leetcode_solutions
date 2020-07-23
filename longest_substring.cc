class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> ht;
        int i = 0, j = 0, max_sub = 0;

        while (i < s.size() && j < s.size()) {
            if (ht.find(s[j]) == ht.end()) {
                // Character not in ht so slide right
                ht.insert(s[j++]);
                // Found a new longest substring
                max_sub = std::max(max_sub, j - i);
            } else {
                // Character in ht so we remove and slide left
                ht.erase(ht.find(s[i++]));
            }
        }
        return max_sub;
    }
};
