class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # topological sort
        # 1. init a dict to save all the nodes and its connected nodes
        # 2. iterate from all the nodes have indegree with 1
        # 3. where encounter the last node with indegree > 1, then stop
        # 4. re-iterate edge to find the last edge with this vertice ??
        indegree = defaultdict(int)
        neighbors = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            neighbors[x].append(y)
            neighbors[y].append(x)
            indegree[x] += 1
            indegree[y] += 1
        
        curr = deque()
        for k, v in indegree.items():
            if v == 1:
                curr.append(k)

        while curr:
            v = curr.popleft()
            indegree[v] -= 1
            for n in neighbors[v]:
                indegree[n] -= 1
                if (indegree[n] == 1):
                    curr.append(n)

        for x, y in edges[::-1]:
            if indegree[x] > 0 and indegree[y] > 0:
                return[x, y]
        
        