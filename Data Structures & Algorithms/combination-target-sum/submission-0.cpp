class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, target, cur, ans, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int target, vector<int>& cur, vector<vector<int>>& ans, int start) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || target < nums[start]) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, target - nums[i], cur, ans, i);
            cur.pop_back();
        }
    }

};
