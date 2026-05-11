class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # prim
        # releax the edges n-1 times
        N = len(points)
        visited = [False] * (N + 1)
        minDist = [float('Inf')] * (N + 1)
        hq = [(0, 0)]   # weight, index
        heapq.heapify(hq)
        ans = 0
        while hq:
            minD, curr = heapq.heappop(hq)
            if visited[curr]:
                continue
            visited[curr] = True
            ans += minD
            for i in range(N):
                if not visited[i]:
                    md = abs(points[i][0] - points[curr][0]) + abs(points[i][1] - points[curr][1])
                    if minDist[i] > md:
                        heapq.heappush(hq, (md, i))
                        minDist[i] = md
        
        return ans