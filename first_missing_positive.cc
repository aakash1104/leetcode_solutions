class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> ht;
        int start = 1;
        
        for (auto &e : nums)
            ht.insert(e);
        
        while (true) {
            if (ht.find(start) == ht.end())
                return start;
            start++;
        }
        
        return 0;
    }
};
