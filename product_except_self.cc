class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> L(nums.size()), R(nums.size());
        std::vector<int> prod(nums.size());
        
        // Base case
        L[0] = 1;
        R[R.size() - 1] = 1;
        
        for (int i = 1; i < nums.size(); i++)
            L[i] = nums.at(i - 1) * L[i - 1];
        
        for (int i = nums.size() - 2; i >= 0; i--)
            R[i] = nums.at(i + 1) * R[i + 1];
        
        for (int i = 0; i < prod.size(); i++)
            prod[i] = L[i] * R[i];
        
        return prod;
        
    }
};
