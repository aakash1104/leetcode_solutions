class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low_link.resize(n);
        rank.resize(n);

        int r = 1; // Initial rank of node 0

        BuildGraph(n, connections);
        // Start DFS from node 0
        DFS(0, -1, r);

        return articulation_points;
    }

private:
    std::vector<std::vector<int>> articulation_points;
    std::vector<std::vector<int>> adj_list;

    std::vector<int> low_link;
    std::vector<int> rank;


    void BuildGraph(int n, vector<vector<int>> &connections) {
        adj_list.resize(n);
        for (auto edge : connections) {
            adj_list[edge[0]].emplace_back(edge[1]);
            adj_list[edge[1]].emplace_back(edge[0]);
        }
    }

    void DFS(int node, int parent, int &r) {
        if (rank.at(node) > 0)
            // Already visited
            return;

        rank.at(node) = low_link.at(node) = r++;

        for (auto adj : adj_list.at(node)) {
            if (adj == parent)
                continue;

            if (rank.at(adj) == 0)
                // Not visited yet then DFS
                DFS(adj, node, r);

            // Update Low link for the node
            low_link.at(node) = std::min(low_link.at(node), low_link.at(adj));
        }

        // Perform articulation point check
        if (parent != -1 && low_link.at(node) > rank.at(parent))
            articulation_points.push_back({node, parent});
    }


};
