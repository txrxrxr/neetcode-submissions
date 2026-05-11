class Node:
    def __init__(self):
        self.neigh= {}
        self.isEnd = False

class WordDictionary:

    def __init__(self):
        self.head = Node()

    def addWord(self, word: str) -> None:
        curr = self.head
        for c in word:
            if c not in curr.neigh:
                newNode = Node()
                curr.neigh[c] = newNode
            curr = curr.neigh[c]
        curr.isEnd = True

    def search(self, word: str) -> bool:
        """
        DFS starting from first node of '.'
        """
        curr = self.head
        for i in range(len(word)):
            if word[i] == '.':
                return self.dfs(word, i, curr)
            else:
                if word[i] not in curr.neigh:
                    return False
                curr = curr.neigh[word[i]]
        return curr.isEnd
    
    def dfs(self, word, idx, curr) -> bool:
        # if idx > len(word):
        #     return False
        # if idx == len(word) - 1 and not curr.isEnd:
        #     return False
      
        for i in range(idx, len(word)):
            if word[i] == '.':
                for n in curr.neigh.values():
                    if self.dfs(word, i + 1, n):
                        return True
                return False
            else:
                if word[i] not in curr.neigh:
                    return False
                curr = curr.neigh[word[i]]
        return curr.isEnd

        
