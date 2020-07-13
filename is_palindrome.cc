class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        size_t reverse = 0;

        if (x < 0) return false;

        while (x) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
        return (num == reverse);
    }
};
