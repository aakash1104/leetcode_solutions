typedef std::pair<int, int> Pair;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        std::map<int, int> OPT;
        std::unordered_map<int, vector<Pair>> jobs;
        
        int max_profit = 0;
        
        // Initialize DP conditions
        for (int i = 0; i < startTime.size(); i++) {
            OPT[startTime[i]] = 0;
            jobs[startTime[i]].push_back({endTime[i], profit[i]});
        }
        
        // Traverse the tree from right to left
        for (auto it = OPT.rbegin(); it != OPT.rend(); it++) {
            // Get associaited job
            for (auto job : jobs[it->first]) {
                
                auto i = OPT.lower_bound(job.first);
                // Make a decision. Max of current profit or (profit from start time + current profit)
                max_profit = std::max(max_profit, (i == OPT.end() ? 0 : i->second) + job.second);
            }
            // Update profit for that start time
            it->second = max_profit;
        }
        return max_profit;
    }
};
