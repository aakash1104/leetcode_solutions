class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        vector<int> A;
        vector<int> B;
        vector<int> C;
        
        for (auto &e : v) {
            if (e < 0)
                A.push_back(e * e);
            else
                B.push_back(e * e);
        }
        
        int i = A.size() - 1;
        int j = 0;
        
        while (i >= 0 && j < B.size()) {
            if (A[i] <= B[j])
                C.push_back(A[i--]);
            else
                C.push_back(B[j++]);
            
        }

        if (i >= 0)
            while (i < A.size())
                C.push_back(A[i--]);
        
        else if (j < B.size())
            while (j < B.size())
                C.push_back(B[j++]);
        
        return C;
    }
};
