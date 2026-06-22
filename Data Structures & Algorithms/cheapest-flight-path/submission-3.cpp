class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman-Ford: relax all edges k + 1 times
        static constexpr int INF = std::numeric_limits<int>::max();
        std::vector<int> minDist(n, INF);
        minDist[src] = 0;
        bool updated = false;

        while (k-- >= 0) {
            std::vector<int> minDistCopy(minDist);
            for (int i = 0; i < flights.size(); ++i) {
                const auto& t = flights[i];
                // Relax: Read source from snapshot, validate/write to the live array
                if (minDistCopy[t[0]] != INF && minDistCopy[t[0]] + t[2] < minDist[t[1]]) {
                    minDist[t[1]] = minDistCopy[t[0]] + t[2];
                    updated = true;
                }
            }
            if (!updated)
                break;
        }
        
        return minDist[dst] == INF ? -1 : minDist[dst];
    }
};
