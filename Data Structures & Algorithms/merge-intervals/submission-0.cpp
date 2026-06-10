class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        vector<vector<int>> ans;
        std::sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2){
            return v1[0] < v2[0];
        });

        for (size_t i = 0; i < intervals.size(); ++i) {
            if (ans.empty()) {
                ans.push_back(intervals[i]);
                continue;
            }

            auto& prev = ans.back();
            const auto& curr = intervals[i];
            if (prev[1] >= curr[0]) {
                // overlap -> merge
                prev[1] = std::max(prev[1], curr[1]);
            } else {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};
