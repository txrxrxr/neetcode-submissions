struct Node {
  Node() { next = std::vector<std::unique_ptr<Node>>(26); }

  std::vector<std::unique_ptr<Node>> next;
  bool isEnd = false;
};

class Trie {
 public:
  Trie() { head = std::make_unique<Node>(); }

  ~Trie() {}

  void insert(const std::string& str) {
    auto cur = head.get();

    for (const char c : str) {
      if (!cur->next[c - 'a']) {
        cur->next[c - 'a'] = std::make_unique<Node>();
      }
      cur = cur->next[c - 'a'].get();
    }
    cur->isEnd = true;
  }

  bool search(const std::string& str) {
    auto cur = head.get();
    int idx = 0;
    for (const char c : str) {
      if (!cur->next[c - 'a']) {
        break;
      }
      cur = cur->next[c - 'a'].get();
      if (idx == str.size() - 1 && cur->isEnd) {
        return true;
      }
      ++idx;
    }
    return false;
  }

  std::unique_ptr<Node> head;
};

class Solution {
 public:
  int minExtraChar(string s, vector<string>& dictionary) {
    // 1. build a trie using dictonary
    Trie t; // issue with Trie t(); -> this is function declaration
    for (const auto& str : dictionary) {
      t.insert(str);
    }

    std::vector<int> dp(s.size(), -1);  // min extra chars to remove within s[i..end of str]
    return dfs(t, dp, 0, s);
  }

  int dfs(Trie& t, std::vector<int>& dp, int start, const string& s) {
    if (start == s.size()) {
      return 0;
    }

    if (dp[start] != -1) {
      return dp[start];
    }

    int ans = 1 + dfs(t, dp, start + 1, s);  // skip char at s[i]
    auto curr = t.head.get();

    for (int i = start; i < s.size(); ++i) {
      if (!curr->next[s[i] - 'a']) {
        break;
      }
      curr = curr->next[s[i] - 'a'].get();
      if (curr->isEnd) {
        ans = min(ans, dfs(t, dp, i + 1, s));
      }
    }

    dp[start] = ans;
    return ans;
  }
};