class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 2 pointer
        int i = 0;
        int j = heights.size() - 1;
        int ans = -1;

        while (i < j) {
            ans = std::max(ans, std::min(heights[i], heights[j]) * (j - i));
            if (heights[i] < heights[j]) {
                ++i;
            } else {
                --j;
            }
        }

        return ans;
    }
};
