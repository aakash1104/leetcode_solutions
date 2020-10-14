class Solution {
public:
    string sortString(string s) {
        string res;
        vector<int> freq(26, 0);
       
        for (auto c : s)
            freq[c - 'a']++;
        
        bool flag = true;
        
        while(flag) {
            flag = false;
            // Generate increasing string
            for (int i = 0; i < 26; i++) {
                if (freq[i]) {
                    char ch = i + 'a';
                    res.push_back(ch);
                    freq[i]--;
                    flag = true;
                }
            }
            // Generate decreasing string
            for (int i = 25; i >= 0; i--) {
                if (freq[i]) {
                    char ch = i + 'a';
                    res.push_back(ch);
                    freq[i]--;
                    flag = true;
                }
            }
        }
        return res;
    }

};
