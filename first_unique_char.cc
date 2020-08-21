class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) 
            return -1;
        
        std::unordered_map<char, int> ht;
        std::vector<int> v(26, 0);
        
        ht.emplace(s[0], 0);
        
        for (int i = 1; i < s.size(); i++) {
            if (ht.find(s[i]) == ht.end() && v.at(s[i] - 'a') == 0)
                // Haven't seen it before so it could be unique?
                ht.emplace(s[i], i);
            
            else if (ht.find(s[i]) != ht.end()) {
                // Already seen this character
                ht.erase(s[i]);
                v.at(s[i] - 'a') = 1;
            }
            
            else
                continue;
        }
        
        if (ht.empty())
            return -1;
        
        int min_idx = std::numeric_limits<int>::max();
        for (auto &e : ht)
            min_idx = std::min(min_idx, e.second);
        
        return min_idx;
    }
};
