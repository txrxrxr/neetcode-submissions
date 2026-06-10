class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        vector<bool> visited(row*col, false);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(i, j, board, word, 0, visited))
                    return true;
            }
        }
        
        return false;
    }

    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int sIdx, vector<bool>& visited) {
        if (sIdx == word.size()) {
            return true;
        }

        if (i < 0 || i >= row || j < 0 || j >= col || visited[i * col + j] || board[i][j] != word[sIdx]) {
            return false;
        }

        visited[i * col + j] = true;

        for (const auto [x, y] : dirs) {
            int ni = i + x, nj = j + y;
            if (dfs(ni, nj, board, word, sIdx + 1, visited))
                return true;
        }

        visited[i * col + j] = false;

        return false;
    }

private:
    const int dirs[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    int row;
    int col;

};
