class Solution:
    def __init__(self):
        self.dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        self.inf = pow(2, 31) - 1
    
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        queue = deque()
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == 0:
                    queue.append((row, col))
        self.bfs(grid, queue)

    def bfs(self, grid, queue) -> None:
        dist = 1
        while queue:
            curr = len(queue)
            for i in range(curr):
                x, y = queue.popleft()
                for dx, dy in self.dirs:
                    r = x + dx
                    c = y + dy
                    if r >= 0 and r < len(grid) and c >= 0 and c < len(grid[0]) and grid[r][c] == self.inf:
                        grid[r][c] = dist
                        queue.append((r, c))
            dist += 1
            