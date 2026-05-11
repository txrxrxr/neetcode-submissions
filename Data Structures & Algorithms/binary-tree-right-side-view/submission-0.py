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
            rightNode = None
            for i in range(sz):
                rightNode = queue.popleft()
                if rightNode.left:
                    queue.append(rightNode.left)
                if rightNode.right:
                    queue.append(rightNode.right)
            if rightNode:
                ans.append(rightNode.val)
        return ans
