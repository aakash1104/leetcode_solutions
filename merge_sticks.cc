class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() == 1)
            return 0;
        // build min heap from vector
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int work = 0;

        for (auto e : sticks)
            pq.push(e);

        while (!pq.empty()) {
            if (pq.size() == 1)
                pq.pop();

            else {
                int min = pq.top();
                pq.pop();
                int min2 = pq.top();
                pq.pop();
                int l = min + min2;
                work += l;
                pq.push(l);
            }
        }
        return work;
    }
};
