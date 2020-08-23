class Solution {
public:
    int numTrees(int n) {
        vector<int> OPT(n + 1);
        // Base case
        OPT[0] = OPT[1] = 1;
        
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                OPT[i] += OPT[j - 1] * OPT[i - j]; 
        
        return OPT[n];
    
    }
};
