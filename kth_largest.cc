class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> pq;

        // O(N log(k))
        for (auto e : nums)
            pq.push(e);

        // O(k log(N))
        while (--k)
            pq.pop();

        return pq.top();

    }
};
