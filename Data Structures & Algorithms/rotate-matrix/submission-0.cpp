class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // rotate by 4 corners
        int r = 0;  // top left
        int c = matrix[0].size() - 1;   // bottom right

        while (r < c) {
            for (int i = 0; i < c - r; ++i) {
                int tl = matrix[r][r+i];

                // bottom left -> top left
                matrix[r][r+i] = matrix[c-i][r];

                // bottom right -> bottom left
                matrix[c-i][r] = matrix[c][c - i];

                // top right -> bottom right
                matrix[c][c - i] = matrix[r + i][c];

                // top left -> top right
                matrix[r+i][c] = tl;

                // // 1. Cache the Top-Left value safely
                // int top_left = matrix[r][r + i];

                // // 2. Move Bottom-Left cell up into Top-Left location
                // matrix[r][r + i] = matrix[c - i][r];

                // // 3. Move Bottom-Right cell left into Bottom-Left location
                // matrix[c - i][r] = matrix[c][c - i];

                // // 4. Move Top-Right cell down into Bottom-Right location
                // matrix[c][c - i] = matrix[r + i][c];

                // // 5. Inject the cached Top-Left cell value into Top-Right location
                // matrix[r + i][c] = top_left;
            }

            r++;
            c--;
        }
    }
};
