#include <print>
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        std::vector<int> ans;
        std::queue<int> q;
        std::vector<int> indegree(numCourses, 0);
        std::unordered_map<int, std::vector<int>> hm;
        for (const auto& preq : prerequisites) {
            hm[preq[1]].push_back(preq[0]); // preq -> crs
            indegree[preq[0]] += 1;
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (const auto& n : hm[curr]) {
                indegree[n] -= 1;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        // check if all crs are taken
        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
    }
};
