class UF:
    def __init__(self, n):
        self.parents = list(range(n))
        self.rank = [0] * n

    def join(self, x1, x2):
        p1 = self.find(x1)
        p2 = self.find(x2)

        if p1 == p2:
            return
        
        if self.rank[p1] < self.rank[p2]:
            p1, p2 = p2, p1
        if self.rank[p1] == self.rank[p2]:
            self.rank[p1] += 1
        
        self.parents[p2] = p1

    def find(self, x):
        if x == self.parents[x]:
            return x
        self.parents[x] = self.find(self.parents[x])
        return self.parents[x]

    def isConnected(self, x1, x2):
        p1 = self.find(x1)
        p2 = self.find(x2)

        if p1 == p2:
            return True
        
        return False

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        """
        kruskal: sort edges + union find
        """
        N = len(grid)
        edges = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                edges.append((grid[i][j], i, j))
        edges.sort()

        uf = UF(N * N)
        self.dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        for w, x, y in edges:
            for i, j in self.dirs:
                x1 = x + i
                y1 = y + j
                if x1 < 0 or x1 >= N or y1 < 0 or y1 >= N or grid[x1][y1] > w:
                    continue
                
                uf.join(x1 * N + y1, x * N + y)
                if uf.isConnected(0, N * N - 1):
                    return w
