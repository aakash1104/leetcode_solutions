class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0, pos = 31;

        while (n) {
            // get the last bit and add to the reversed position
            rev = rev + ((n & 1) << pos);
            pos--;
            n >>= 1;
        }
        return rev;
    }
};
