class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int sum = (1 + digits.back()) % 10;
        if (!sum)
            carry = 1;
        else
            carry = 0;
        
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            if (it == digits.rbegin())
                *it = sum;
            else {
                *it = (*it + carry) % 10;
                if (!*it && carry == 1)
                    carry = 1;
                else
                    carry = 0;
            }
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
