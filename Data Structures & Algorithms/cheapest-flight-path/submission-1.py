class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        hm = defaultdict(list)
        for s, d, p in flights:
            hm[s].append([d, p])
        
        minDist = [float('Inf')] * (n + 1)
        minDist[src] = 0
        que = deque([(0, src, 0)])

        while que:
            dist, cur, cnt = que.popleft()
            if cnt >= k + 1:
                continue
            visited = [False] * (n + 1)
            visited[cur] = True
            tmp = minDist.copy()

            for d, p in hm[cur]:
                if not visited[d]:
                    if tmp[d] > p + dist:
                        minDist[d] = p + dist
                        que.append([minDist[d], d, cnt + 1])
                        visited[d] = True


        return minDist[dst] if minDist[dst] != float('Inf') else -1
