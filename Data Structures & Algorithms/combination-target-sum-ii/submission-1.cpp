class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, cur, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& cur, int start) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i != start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (target - candidates[i] < 0) 
                break;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], ans, cur, i + 1);
            cur.pop_back();
        }
    }
};
