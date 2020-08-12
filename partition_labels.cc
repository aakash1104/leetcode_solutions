class Solution {
public:
    vector<int> partitionLabels(string S) {
        int end = 0, len = 0;
        vector<int> last(26);
        vector<int> p;
        
        for (int i = 0; i < S.size(); i++)
            last.at(S.at(i) - 'a') = i;
        
        for (int i = 0; i < S.size(); i++) {
            // Find the end of the current partition
            end = std::max(end, last.at(S.at(i) - 'a'));
            ++len;
            if (i == end) {
                p.push_back(len);
                len = 0;
            }
        }
        
        return p;
    }
};
