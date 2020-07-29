class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        std::vector<int> vec(T.size(), 0);
        std::vector<int> next(101, INT_MAX);

        for (int i = T.size() - 1; i >= 0; i--) {
            int min_idx = INT_MAX;
            for (int j = T[i] + 1; j <= 100; j++) {
                min_idx = std::min(min_idx, next[j]);
            }
            if (min_idx != INT_MAX)
                vec[i] = min_idx - i;
            next[T[i]] = i;
        }
        return vec;
    }
};
