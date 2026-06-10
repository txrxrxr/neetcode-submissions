class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        std::sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2){
            return v1[0] < v2[0];
        });

        ans.push_back(std::move(intervals[0]));

        for (size_t i = 1; i < intervals.size(); ++i) {
            auto& prev = ans.back();
            auto& curr = intervals[i];
            if (prev[1] >= curr[0]) {
                // overlap -> merge
                prev[1] = std::max(prev[1], curr[1]);
            } else {
                ans.push_back(std::move(curr));
            }
        }

        return ans;
    }
};
