class Solution {
public:
    bool isStrobogrammatic(string num) {
        std::string build;
        std::unordered_map<int, char> m = { {0, '0'}, {1, '1'}, {6, '9'}, 
            {8, '8'}, {9, '6'} };
        
        for (auto rit = num.rbegin(); rit != num.rend(); ++rit) {
            if (m.find(*rit - '0') == m.end())
                // Number not invertible
                return false;
            build += m.find(*rit - '0')->second;
        }
        return (build == num);
    }
};
