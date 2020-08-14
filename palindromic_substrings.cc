class Solution {
public:
    int countSubstrings(string s) {
        std::unordered_set<string> ht;
        int N = s.size();
        int ans = 0;
        for (int center = 0; center <= (2 * N) - 1; center++) {
            int left = center / 2;
            int right = left + (center % 2);
            while (left >= 0 && right < N && s.at(left) == s.at(right)) {
                
                // if (ht.find(s.substr(left, right - left + 1)) == ht.end()) {
                //     cout << "Palindrome string is " << s.substr(left, right - left + 1) << endl;
                //     // ans++;
                //     ht.insert(s.substr(left, right - left + 1));
                // }
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
