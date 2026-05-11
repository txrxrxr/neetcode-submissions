class CharNode:
    def __init__(self):
        self.next = {}
        self.isEnd = False

class PrefixTree:

    def __init__(self):
        self.head = CharNode()

    def insert(self, word: str) -> None:
        cur = self.head
        for c in word:
            if c not in cur.next:
                cur.next[c] = CharNode()
            cur = cur.next[c]
          
        cur.isEnd = True

    def search(self, word: str) -> bool:
        cur = self.head
        for c in word:
            if c not in cur.next:
                return False
            cur = cur.next[c]
        
        return cur.isEnd
        

    def startsWith(self, prefix: str) -> bool:
        cur = self.head
        for c in prefix:
            if c not in cur.next:
                return False
            cur = cur.next[c]
        
        return True
        
        