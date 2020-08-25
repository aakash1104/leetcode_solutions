typedef std::pair<int, int> Pair;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v;
        std::priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        // O(N)
        for (auto &e : arr)
            pq.push(std::make_pair(CountBits(e), e));
        
        // O(N log(N))
        while (!pq.empty()) {
            auto info = pq.top();
            v.push_back(info.second);
            pq.pop();
        }
        
        return v;
    }
    
private:
    int CountBits(int num) {
        int count = 0;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }
};
