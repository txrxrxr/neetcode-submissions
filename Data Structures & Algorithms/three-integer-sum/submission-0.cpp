class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<pair<int, int>> res;
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            res = twoSum(nums, i + 1, -nums[i]);
            for (const auto [p1, p2] : res) {
                ans.push_back({nums[i], nums[p1], nums[p2]});
                res.clear();
            }
        }
        return ans;
    }

    vector<pair<int, int>> twoSum(vector<int>& nums, const size_t i, const int target) {
        vector<pair<int, int>> ans;
        size_t start = i;
        size_t end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                ans.push_back(std::make_pair(start, end));
                while (start < end && nums[start] == nums[start + 1]) {
                    ++start;
                }
                while (start < end && nums[end] == nums[end - 1]) {
                    --end;
                }
                ++start;
                --end;
            } else if (nums[start] + nums[end] > target) {
                --end;
            } else {
                ++start;
            }
        }
        return ans;
    }
};
