class Solution {
public:
    string generateTheString(int n) {
        if (!n)
            return "";
        
        std::string s;
        s.resize(n);
        
        for (int i = 0; i < n; i++)
            s.at(i) = 'x';
        
        if (n % 2 == 0)
            s.at(0) = 'y';
        return s;
    }
};
