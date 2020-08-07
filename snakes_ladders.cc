class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        std::queue<int> q;
        std::unordered_map<int, int> dist;
        
        dist.emplace(1, 0);
        q.push(1);
        
        // Start BFS procedure
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            
            if (p == N * N) 
                return  dist.at(p);
            
            for (int i = p + 1; i <= std::min(p + 6, N * N); i++) {
                int coord = GetCoordinates(i, N);
                int row = coord / N;
                int col = coord % N;
                int position = (board[row][col] == -1) ? i : board[row][col];
                
                if (dist.find(position) == dist.end()) {
                    dist.emplace(position, dist.at(p) + 1);
                    q.push(position);
                }
            }
        }
        return -1;
    }

private:
    int GetCoordinates(int i, int N) {
        // Board[r][c] in 1D form is board[r * N + c]
        int quotient = (i - 1) / N;
        int remainder = (i - 1) % N;
        int row = N - 1 - quotient;
        // column depends on if we're in a row numbered regularly or backwards
        int column = (row % 2 != N % 2) ? remainder : N - 1 - remainder;
        return (row * N) + column;
    }
};
