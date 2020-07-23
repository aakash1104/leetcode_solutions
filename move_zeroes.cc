class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!nums[pos]) {
                nums.erase(nums.begin() + pos);
                nums.push_back(0);
            }
            else
                pos++;
        }
    }
};
