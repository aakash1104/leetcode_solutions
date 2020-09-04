class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::istringstream s(str);
        std::vector<string> v;
        
        string w;
        
        // 2 hash tables for bijection
        std::unordered_map<char, string> ht_p;
        std::unordered_map<string, char> ht_s;        
        
        // Get all words delimited by space
        while (s >> w)
            v.push_back(w);

        // If pattern size and vector size aren't the same then no bijection exists
        if (pattern.size() != v.size())
            return false;
        
        // Iterate through the pattern and map characters to words
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern.at(i);
            
            if (ht_p.find(p) == ht_p.end()) {
                // Make sure bijection holds
                if (ht_s.find(v.at(i)) != ht_s.end())
                    return false;
                else {
                    ht_p.emplace(p, v.at(i));
                    ht_s.emplace(v.at(i), p);
                }
            } 
            
            else {
                // Already exists in HT
                string mapped = ht_p.at(p);
                if (mapped != v.at(i))
                    return false;
            }
        }
        
        return true;
    }
};
