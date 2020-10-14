class Solution {
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6;
        long b121, b123;
        long mod = 1e9 + 7;
        
        for (int i = 1; i < n; i++) {
            b121 = (3 * a121) + (2 * a123);
            b123 = (2 * a121) + (2 * a123);
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        
        return (a121 + a123) % mod;
    }
};
