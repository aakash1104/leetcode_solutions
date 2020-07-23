class Solution {
public:
    int findDerangement(int n) {
        const int kModSize = 1000000007;

        if (n == 0) return 1;
        if (n == 1) return 0;

        std::vector<int> vec(n + 1);
        vec.at(0) = 1;
        vec.at(1) = 0;

        for (int i = 2; i < vec.size(); i++)
            vec[i] = ((i - 1L) * (vec[i - 1] + vec[i - 2])) % kModSize;


        return vec.at(n);
    }
};
