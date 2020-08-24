class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            int b = n & 1;
            if (b)
                count++;
            n >>= 1;
        }
        return count;
    }
};
