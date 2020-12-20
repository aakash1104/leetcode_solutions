class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto v = Merge(nums1, nums2);
        
        if (v.size() % 2)
            return v[((v.size() + 1) / 2) - 1];
            
        else
            return ((double)(v[v.size() / 2] + v[(v.size() / 2) - 1])) / 2.0;
        
    }
private:
    vector<int> Merge(vector<int> &p, vector<int> &q) {
        vector<int> v;
        int i = 0, j = 0, pos = 0;
        
        // merge arrays
        while (i < p.size() && j < q.size()) {
            if (p.at(i) < q.at(j))
                v.push_back(p.at(i++));
            else
                v.push_back(q.at(j++));
        }
        
        if (i < p.size())
            while (i < p.size())
                v.push_back(p.at(i++));
        if (j < q.size())
            while (j < q.size())
                v.push_back(q.at(j++));
        
        return v;
    }
};
