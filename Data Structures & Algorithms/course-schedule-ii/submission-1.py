class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # DFS with cycle detection
        ans = []
        preq = defaultdict(list)
        visited = set() # fully taken
        curr = set()    # current dfs path
        for crs, pre in prerequisites:
            preq[crs].append(pre)

        for i in range(numCourses):
            if not self.dfs(i, preq, curr, visited, ans):
                return []
        
        return ans
    
    def dfs(self, crs, preq, curr, visited, ans):
        if crs in visited:
            return True
        if crs in curr:
            return False
        
        curr.add(crs)
        for p in preq[crs]:
            if not self.dfs(p, preq, curr, visited, ans):
                return False
        ans.append(crs)
        visited.add(crs)
        curr.remove(crs)
        return True
        
