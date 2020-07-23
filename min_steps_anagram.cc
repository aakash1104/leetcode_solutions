class Solution {
public:
    int minSteps(string s, string t) {
        if (s.size() != t.size())
            return -1;
        int sum = 0;
        std::vector<int> v(26, 0);
        for (auto c : s)
            v[c - 'a']++;

        for (auto c : t)
            v[c - 'a']--;

        for (int i = 0; i < 26; i++)
            if (v[i] < 0)
                sum += v[i];

        return std::abs(sum);
    }
};
