class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr = 0, left = 0, right = nums.size() - 1;

        while (curr <= right) {
            if (nums[curr] == 0)
                std::swap(nums[curr++], nums[left++]);
            else if (nums[curr] == 2)
                std::swap(nums[curr], nums[right--]);
            else
                curr++;
        }
    }
};
\