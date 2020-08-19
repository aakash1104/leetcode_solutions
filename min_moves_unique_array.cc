class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (!A.size() || A.size() == 1) return 0;
        
        std::sort(A.begin(), A.end());
        
        int moves = 0;
        int max_seen = A.at(0);
        
        for (int i = 1; i < A.size(); i++) {
            // Have to deal with number of moves
            // max_seen - A.at(i) more moves needed
            if (A.at(i) <= max_seen) {
                max_seen++;
                moves += max_seen - A.at(i);
                A.at(i) = max_seen;
            }
            else
                max_seen = A.at(i);
        }
        
        return moves;
    }
};
