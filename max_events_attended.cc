class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b) {
        if (a[1] == b[1])
            return a[0] < b[0];
        
        return a[1] < b[1];    
    }
    
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int max_attended = 0;
        if (n <= 1) 
            return 1;
        
        std::sort(events.begin(), events.end(), comparator);
        set<int> s;
        
        // last day possible is the last finish day events[n - 1][1];
        
        for (int i = 1; i <= events[n - 1][1]; i++)
            // Insert all possible days that we can visit
            s.insert(i);
        
        for (int i = 0; i < n; i++) {
            // Find the nearst available day >= start of event i
            auto nearest_days = s.lower_bound(events[i][0]);
            
            // If no available days OR if that day is only after the finish day of event i
            if (nearest_days == s.end() || *nearest_days > events[i][1])
                continue;
            
            // Else attend the event and make sure to erase that available day
            // We can use an available day only once
            else {
                max_attended++;
                s.erase(nearest_days);    
            }
        }
        
        return max_attended;
    }
};
