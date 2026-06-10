class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // counter of each element
        std::unordered_map<int, int> hm;
        for (const auto& n : nums) {
            hm[n]++;
        }

        // use min-heap to track k most frequent elements
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (const auto& [n, cnt] : hm) {
            pq.push(std::make_pair(cnt, n));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < k; i++) {
            std::pair<int, int> element = pq.top();
            pq.pop();
            ans.push_back(element.second);
        }
        return ans;
    }
};
