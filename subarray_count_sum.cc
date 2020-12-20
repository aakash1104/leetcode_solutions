class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        // map sum to the number of subarrays that have that sum
        std::unordered_map<int, int> ht;
        ht[sum] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            if (ht.find(sum - k) != ht.end())
                // found sum - k
                count += ht[sum - k];
            
            ht[sum]++;
        }
        
        return count;
    }
};
