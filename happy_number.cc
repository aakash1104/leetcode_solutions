class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> ht;
        while (ht.find(n) == ht.end()) {
            auto s = SumOfSquares(n);
            
            if (s == 1)
                return true;
            
            ht.insert(n);
            n = s;
        }
        
        return false;
    }
    
private:
    int SumOfSquares(int n) {
        int s = 0;
        while (n > 0) {
            s += std::pow((n % 10), 2);
            n /= 10;
        }
        return s;
    }
};
