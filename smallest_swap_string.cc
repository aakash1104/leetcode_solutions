class Solution {
public:
    void dfs(int i, vector<int> &pos, vector<bool> &visited, vector<vector<int>> &g) {
        visited[i] = true;
        pos.push_back(i);

        for(auto child: g[i])
            if (!visited[child])
                dfs(child, pos, visited, g);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans = s;

        int n = s.size();
        vector<vector<int>> g(n);

        for(auto i: pairs) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> pos;
                dfs(i, pos, visited, g);

                string build;

                for (auto c : pos)
                    build += s[c];

                std::sort(pos.begin(), pos.end());
                std::sort(build.begin(), build.end());

                for (int j = 0; j < pos.size(); j++)
                    ans[pos[j]] = build[j];
            }
        }

        return ans;
    }
};
