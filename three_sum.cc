class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> sol;
        std::unordered_set<int> ht;

        for (int i = 0; i < nums.size(); i++) {
            // If target has already been seen, no need to re do this.
            if (ht.find(nums.at(i)) != ht.end())
                continue;

            ht.emplace(nums.at(i));
            int tar = -1 * nums.at(i);

            // Is there a 2 sum with target = -nums[i]?
            std::vector<std::vector<int>> twoSum = hasTwoSum(nums, i, tar);

            if (!twoSum.empty()) {
                sol.insert(sol.end(), twoSum.begin(), twoSum.end());
            }
        }
        sort(sol.begin(), sol.end());
        auto ip = std::unique(sol.begin(), sol.end());
        sol.resize(std::distance(sol.begin(), ip));

        return sol;
    }

private:
    vector<vector<int>> hasTwoSum(vector<int> &nums, int pos, int target) {
        std::unordered_map<int, int> ht;
        std::vector<std::vector<int>> vec;

        int t = -1 * target; // Original number
        for (int i = 0; i < nums.size(); i++) {
            if (i == pos) continue;
            ht.emplace(nums[i], i);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == pos) continue;
            auto it = ht.find(target - nums.at(i));

            if (it != ht.end() && it->second != i) {
                // 2 sum candidate
                vector<int> v{t, nums.at(i), it->first};
                // Since there's always only 3 elements, sorting is constant time
                sort(v.begin(), v.end());
                vec.push_back(v);
            }
        }
        return vec;
    }
};
