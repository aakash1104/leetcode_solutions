class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) 
            return -1;
        
        std::vector<int> v(26, 0);
        
        for (auto c : s)
            v.at(c - 'a')++;
        
        for (int i = 0; i < s.size(); i++)
            if (v[s[i] - 'a'] == 1)
                return i;
        
        return -1;
    }
};
