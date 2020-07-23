class Solution {
public:
    bool isArmstrong(int N) {
        string num = std::to_string(N);
        int sum = 0;
        for (auto d : num)
            sum += std::pow(d - '0', num.size());
        return sum == N;
    }
};
