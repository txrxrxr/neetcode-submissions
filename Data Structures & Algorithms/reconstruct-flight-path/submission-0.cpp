class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Eulerian Paths + Hierholzer's algorithm
        // An Euler path is a path that visits each edge exactly once.
        vector<string> ans;
        std::unordered_map<string, priority_queue<string, std::vector<string>,std::greater<string>>> ft;
        for (const auto& t: tickets) {
             ft[t[0]].push(t[1]);
        }
        std::deque<string> que;
        que.push_back("JFK");
        std::string cur = "JFK";

        while (!que.empty()) {
            cur = que.back();
            if (ft[cur].empty()) {
                ans.emplace_back(cur);
                que.pop_back();
            } else {
                auto& nxt = ft[cur];
                que.push_back(nxt.top());
                nxt.pop();
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
