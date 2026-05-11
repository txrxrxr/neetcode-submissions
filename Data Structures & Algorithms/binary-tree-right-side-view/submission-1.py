# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # BFS level traversal
        if not root:
            return []
        ans = []
        queue = deque([root])
        while queue:
            sz = len(queue)
            node = None
            for _ in range(sz):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if node:
                ans.append(node.val)
        return ans
