class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        std::unordered_map<std::string, std::vector<string>> ht;

        // O(N KlogK) where N = number of strings, K is the length of
        // longest word
        for (auto word : strs) {
            string check = word;
            std::sort(check.begin(), check.end());
            if (ht.find(check) == ht.end()) {
                // Not in ht
                std::vector<string> v{word};
                ht.insert(std::make_pair(check, v));
            } else {
                ht.find(check)->second.emplace_back(word);
            }
        }

        // O(Number of groups)
        for (auto group : ht)
            groups.push_back(group.second);

        return groups;
    }
};
