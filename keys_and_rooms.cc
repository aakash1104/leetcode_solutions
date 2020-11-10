class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited.at(0) = true;
        // stack<int> s;
        // s.push(0);
        
        DFS(0, rooms, visited);
        
        // while (!s.empty()) {
        //     int node = s.top();
        //     s.pop();
        //     for (auto &neighbor: rooms.at(node)) {
        //         if (!visited.at(neighbor)) {
        //             visited.at(neighbor) = true;
        //             s.push(neighbor);
        //         }
        //     }
        // } // DFS
        
        for (auto v : visited)
            if (!v)
                return false;
        return true;
        
    }
private:
    void DFS(int src, vector<vector<int>> &rooms, vector<bool> &visited) {
        for (auto &neighbor : rooms.at(src)) {
            if (!visited.at(neighbor)) {
                visited.at(neighbor) = true;
                DFS(neighbor, rooms, visited);
            }
        }
    }

};
