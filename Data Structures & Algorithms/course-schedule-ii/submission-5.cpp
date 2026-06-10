#include <print>
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // topological sort + DFS
    std::vector<int> ans;
    ans.reserve(numCourses);
    std::vector<int> indegree(numCourses, 0);
    std::vector<std::vector<int>> graph(numCourses);

    for (const auto& preq : prerequisites) {
      graph[preq[1]].push_back(preq[0]);  // preq -> crs
      indegree[preq[0]] += 1;
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        dfs(i, graph, indegree, ans);
      }
    }

    // check if all crs are taken
    if (ans.size() == numCourses) {
      return ans;
    }

    return {};
  }

  void dfs(int crs, const std::vector<std::vector<int>>& graph,
           std::vector<int>& indegree, std::vector<int>& ans) {
            ans.push_back(crs);
            --indegree[crs];
            for (int n : graph[crs]) {
                --indegree[n];
                if (indegree[n] == 0) {
                    dfs(n, graph, indegree, ans);
                }
            }
           }
};
