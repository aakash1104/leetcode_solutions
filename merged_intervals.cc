class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        std::sort(intervals.begin(), intervals.end());

        if (!intervals.empty())
            merged.emplace_back(intervals[0]);

        for (auto interval : intervals) {
            if (merged.back()[1] < interval[0])
                merged.emplace_back(interval);
            else
                merged.back()[1] = std::max(interval[1], merged.back()[1]);
        }
        return merged;
    }
};
