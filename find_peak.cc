class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return BinarySearch(nums, 0, nums.size() - 1);
    }
private:
    int BinarySearch(std::vector<int> &nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums.at(mid) > nums[mid + 1])
            // Peak is somewhere in the left
            return BinarySearch(nums, l, mid);
        // Peak is in the right half
        return BinarySearch(nums, mid + 1, r);
    }
};
