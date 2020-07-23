class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        std::string fraction;

        if (numerator < 0 ^ denominator < 0)
            fraction.append("-");

        long dividend = std::abs(static_cast<long>(numerator));
        long divisor = std::abs(static_cast<long>(denominator));
        fraction.append(std::to_string(dividend / divisor));

        long remainder = dividend % divisor;
        if (!remainder)
            return fraction;

        fraction.append(".");
        std::unordered_map<long, int> ht;
        while (remainder != 0) {
            if (ht.find(remainder) != ht.end()) {
                int pos = ht.find(remainder)->second;
                fraction.insert(fraction.begin() + pos, '(');
                fraction.append(")");
                break;
            }
            ht.emplace(remainder, fraction.size());
            remainder *= 10;
            fraction.append(std::to_string(remainder / divisor));
            remainder %= divisor;
        }

        return fraction;

    }
};
