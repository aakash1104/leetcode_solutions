class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> ht;

        for (int i = 0; i < nums.size(); ++i)
            ht.emplace(nums.at(i), i);

        for (int i = 0; i < nums.size(); ++i) {
            auto it = ht.find(target - nums.at(i));
            // make sure found target is at a different index than the current
            // one
            if (it != ht.end() && it->second != i) {
                vector<int> v{i, it->second};
                return v;
            }
        }
        return {};
    }

};
