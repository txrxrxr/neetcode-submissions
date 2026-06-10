#include <print>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, std::string(n, '.'));
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
            bool isValid = true;
            while (r > 0) {
                if (cur[r-1][col] == 'Q') {
                    isValid = false;
                    break;
                }
                --r;
            }

            // check top left
            r = row; 
            int c = col;
            while (isValid && r > 0 && c > 0) {
                if (cur[r-1][c-1] == 'Q') {
                    isValid = false;
                    break;
                }
                --r;
                --c;
            }

            // check top right
            r = row;
            c = col;
            while (isValid && r > 0 && c < n - 1) {
                if (cur[r-1][c+1] == 'Q'){
                    isValid = false;
                    break;
                }
                --r;
                ++c;
            }
            
            if (!isValid) {
                continue;
            }

            cur[row][col] = 'Q';
            // std::print("pushed Q at {} {}\n", row, col);
            dfs(n, ans, cur, row + 1);
            cur[row][col] = '.';
        }
    }
};
