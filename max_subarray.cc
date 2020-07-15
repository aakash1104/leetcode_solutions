class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> OPT(nums.size());
        OPT[0] = nums[0];
        int max = OPT[0];
        for (int i = 1; i < nums.size(); ++i) {
            OPT[i] = std::max(OPT[i - 1] + nums[i], nums[i]);
            max = std::max(max, OPT[i]);
        }
        return max;
    }
};
