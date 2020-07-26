class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> idx;
        std::unordered_map<char, int> p_ht;
        std::unordered_map<char, int> s_ht;

        for (auto c : p) {
            if (p_ht.find(c) == p_ht.end())
                p_ht.emplace(c, 1);
            else
                p_ht.find(c)->second++;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            if (s_ht.find(c) == s_ht.end())
                s_ht.emplace(c, 1);
            else
                s_ht.find(c)->second++;

            if (i >= p.size()) {
                c = s.at(i - p.size());
                if (s_ht.find(c)->second == 1)
                    s_ht.erase(c);
                else
                    s_ht.find(c)->second--;
            }
            if (s_ht == p_ht)
                idx.push_back(i - p.size() + 1);
        }

        return idx;
    }
};
