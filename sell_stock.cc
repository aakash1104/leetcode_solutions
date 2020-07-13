class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = std::numeric_limits<int>::max();
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            min = (prices.at(i) < min) ? prices.at(i) : min;

            max_profit = (prices.at(i) - min > max_profit) ?
                prices.at(i) - min : max_profit;
        }
        return max_profit;
    }
};
