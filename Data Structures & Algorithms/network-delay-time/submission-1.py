class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        """
        dijkstra alg
        """
        edges = defaultdict(list)
        for u, v, t in times:
            edges[u].append((v, t))
        minDist = [float('Inf')] * (n + 1)
        visited = [False] * (n + 1)
        hq = []
        heapq.heappush(hq, (0, k))
        minDist[k] = 0

        while hq:
            # pop the most closest vertice
            minD, v = heapq.heappop(hq)
            if visited[v]:
                continue
            visited[v] = True

            for next, t in edges[v]:
                if not visited[next] and minD + t < minDist[next]:
                    minDist[next] = minD + t
                    heapq.heappush(hq, (minDist[next], next))

        return -1 if max(minDist[1:]) == float('Inf') else max(minDist[1:])

                
