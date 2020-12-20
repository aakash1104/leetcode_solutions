class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int num_circles = 0;

        for (int i = 0; i < M.size(); i++) {
            if (!visited.at(i)) {
                DFS(i, M, visited);
                num_circles++;
            }
        }
        return num_circles;

    }
private:
    void DFS(int src, vector<vector<int>> &M, vector<bool> &visited) {
        for (int i = 0; i < M.size(); i++) {
            if (M[src][i] && !visited.at(i)) {
                visited.at(i) = true;
                DFS(i, M, visited);
            }
        }
    }
};
