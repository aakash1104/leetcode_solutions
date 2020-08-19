class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> OPT(amount + 1);
        OPT[0] = 1;

        for (auto c : coins)
            for (int i = c; i < amount + 1; i++)
                OPT[i] += OPT[i - c];

        return OPT[amount];
    }
};
