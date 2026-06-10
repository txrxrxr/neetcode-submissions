class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> cur;
        dfs(nums, res, cur, visited);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& visited) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
            cur.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, res, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }
};
