class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # topological sort + DFS
        # why: start from crs has no preq, then use DFS to find crs needs it?
        # so the order is from preq to crs
        indegree = [0] * numCourses
        preqs = defaultdict(list)
        for crs, preq in prerequisites:
            preqs[preq].append(crs)
            indegree[crs] += 1
        
        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)

        ans = []
        while queue:
            curr = queue.popleft()
            ans.append(curr)
            for nxt in preqs[curr]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)
        print(ans)
        return ans if len(ans) == numCourses else []
                        
