class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        self.dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        N = len(grid)
        visited = [[False] * N for _ in range(N)]
        visited[0][0] = True
        minTime = [[grid[0][0], [0, 0]]] # time, index pair
        heapq.heapify(minTime)
        
        while minTime:
            time, curr = heapq.heappop(minTime)
            if curr == [N-1, N-1]:
                return time
            
            # print(f"visited {curr} with time {time}")
            for x, y in self.dirs:
                x1 = curr[0] + x
                y1 = curr[1] + y
                if x1 < 0 or x1 >= N or y1 < 0 or y1 >= N or visited[x1][y1]:
                    continue
                localMin = max(time, grid[x1][y1])
                heapq.heappush(minTime, [localMin, [x1, y1]])
                visited[x1][y1] = True

        return -1
