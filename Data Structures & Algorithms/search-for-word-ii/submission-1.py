class Node:
    def __init__(self):
        self.neigh = {}
        self.isEnd = False
        self.idx = -1

class Solution:
    def __init__(self):
        self.dirs = [(0,1), (0, -1), (1, 0), (-1, 0)]

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        1. build a trie tree for all the words
        2. search within the board to find the word on the trie tree
        """
        head = Node()
        idx = 0
        for w in words:
            cur = head
            for c in w:
                if c not in cur.neigh:
                    newNode = Node()
                    cur.neigh[c] = newNode
                cur = cur.neigh[c]
            cur.isEnd = True
            cur.idx = idx
            idx += 1
        ans = set()
        r = len(board)
        c = len(board[0])
        for i in range(r):
            for j in range(c):
                if board[i][j] in head.neigh:
                    self.backtrack(head, board, i, j, ans, words)       
        return list(ans)
    
    def backtrack(self, curr, board, i, j, ans, words):
        if board[i][j] == '#':
            return

        curr = curr.neigh[board[i][j]]
        tmp = board[i][j]
        board[i][j] = '#'
        if curr.idx >= 0:
            ans.add(words[curr.idx])
            curr.idx = -1
            # return

        for x, y in self.dirs:
            if i + x < 0 or i + x >= len(board) or j + y < 0 or j + y >= len(board[0]):
                continue
            r = i + x
            c = j + y
            if board[r][c] in curr.neigh:
                self.backtrack(curr, board, r, c, ans, words)
        
        board[i][j] = tmp

