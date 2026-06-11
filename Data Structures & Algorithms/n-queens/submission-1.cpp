#include <print>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, std::string(n, '.'));
        colIdx = std::vector<int>(n, 0);
        pIdx = std::vector<int>(n * 2 - 1, 0);
        nIdx = std::vector<int>(n * 2 - 1, 0);
        dfs(n, ans, cur, 0);
        return ans;
    }

    void dfs(int n, vector<vector<string>>& ans, vector<string>& cur, int row) {
        if (n == row) {
            ans.push_back(cur);
            return;
        }

        // iterate each column
        for (int col = 0; col < n; ++col) {
            // check row at top
            int r = row;
            if (colIdx[col] || pIdx[row + col] || nIdx[row - col + n - 1])
                continue;

            // bool isValid = true;
            // while (r > 0) {
            //     if (cur[r-1][col] == 'Q') {
            //         isValid = false;
            //         break;
            //     }
            //     --r;
            // }

            // // check top left
            // r = row; 
            // int c = col;
            // while (isValid && r > 0 && c > 0) {
            //     if (cur[r-1][c-1] == 'Q') {
            //         isValid = false;
            //         break;
            //     }
            //     --r;
            //     --c;
            // }

            // // check top right
            // r = row;
            // c = col;
            // while (isValid && r > 0 && c < n - 1) {
            //     if (cur[r-1][c+1] == 'Q'){
            //         isValid = false;
            //         break;
            //     }
            //     --r;
            //     ++c;
            // }
            
            // if (!isValid) {
            //     continue;
            // }

            cur[row][col] = 'Q';
            colIdx[col] = 1;
            pIdx[row + col] = 1;
            nIdx[row - col + n - 1] = 1;
            // std::print("pushed Q at {} {}\n", row, col);
            dfs(n, ans, cur, row + 1);
            cur[row][col] = '.';
            colIdx[col] = 0;
            pIdx[row + col] = 0;
            nIdx[row - col + n - 1] = 0;
        }
    }
private:
    std::vector<int> colIdx;
    std::vector<int> pIdx;
    std::vector<int> nIdx;

};
