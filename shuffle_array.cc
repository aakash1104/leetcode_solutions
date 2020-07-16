class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int second_half = n;
        int offset = 1;

        for (int i = 0; i < n; i++) {
            nums.insert(nums.begin() + offset, nums.at(second_half));
            nums.erase(nums.begin() + ++second_half);
            offset += 2;
        }

        return nums;
    }
};
