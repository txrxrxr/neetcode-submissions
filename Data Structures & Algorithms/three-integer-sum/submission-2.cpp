class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(nums.size());
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            twoSum(nums, i, -nums[i], ans);
        }
        return ans;
    }

    void twoSum(const vector<int>& nums, const size_t pivot, const int target, vector<vector<int>>& ans) {
        size_t start = pivot + 1;
        size_t end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                ans.push_back({nums[pivot], nums[start], nums[end]});
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
    }
};
