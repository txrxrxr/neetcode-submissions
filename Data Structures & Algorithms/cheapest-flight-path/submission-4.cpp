class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // SPFA: relax prev updated edges k + 1 times
    static constexpr int INF = 1001;
    std::vector<int> minDist(n, INF);
    minDist[src] = 0;
    std::queue<int> que;
    que.emplace(src);
    std::vector<std::vector<std::pair<int, int>>> ft(n);
    // ft.reserve(n);   // IMPORTANT: reserve() does not change the size of vector; cannot directly
    // access by idx
    for (const auto& f : flights) {
      ft[f[0]].emplace_back(f[1], f[2]);
    }

    while (k-- >= 0 && !que.empty()) {
      std::vector<int> minDistCopy(minDist);
      int queSize = que.size();
      while (queSize-- > 0) {
        int s = que.front();
        que.pop();
        for (const auto& [d, p] : ft[s]) {
          if (minDistCopy[s] != INF && minDistCopy[s] + p < minDist[d]) {
            minDist[d] = minDistCopy[s] + p;
            que.emplace(d);
          }
        }
      }
    }

    return minDist[dst] == INF ? -1 : minDist[dst];
  }
};
