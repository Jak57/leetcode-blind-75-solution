// Trie

class WordDictionary {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
    };
    
    TrieNode* getNode() {
        int i;
        TrieNode* node = new TrieNode;
        for (i = 0; i < 26; i++)
            node->child[i] = NULL;
        node->isEnd = false;
        return node;
    }
    
    TrieNode* root;
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        int i, n, idx;
        n = word.size();
        
        for (i = 0; i < n; i++) {
            idx = word[i] - 'a';
            if (cur->child[idx] == NULL)
                cur->child[idx] = getNode();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool dfs(TrieNode* cur1, string word, int startIndex) {
        int i, idx, n, j;
        n = word.size();
        TrieNode* cur = cur1;
        
        for (i = startIndex; i < n; i++) {
            if (word[i] == '.') {
                for (j = 0; j < 26; j++) {
                    if (cur->child[j] != NULL) {
                        if (dfs(cur->child[j], word, i+1))
                            return true;
                    }
                }
                return false;
            } else {
                idx = word[i] - 'a';
                if (cur->child[idx] == NULL)
                    return false;
                cur = cur->child[idx];
            }
        }
        return cur->isEnd;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        return dfs(cur, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
