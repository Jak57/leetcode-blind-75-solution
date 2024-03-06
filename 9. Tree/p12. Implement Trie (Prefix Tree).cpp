// https://www.geeksforgeeks.org/trie-insert-and-search/

class Trie {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isEnd;
    };
    
    TrieNode* getNode() {
        TrieNode* node = new TrieNode;
        int i;
        for (i = 0; i < 26; i++) {
            node->child[i] = NULL;
        }
        node->isEnd = false;
        return node;
    }
    
    TrieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        int i, idx, n;
        n = word.size();
        TrieNode* cur = root;
        
        for (i = 0; i < n; i++) {
            idx = word[i] - 'a';
            if (cur->child[idx] == NULL)
                cur->child[idx] = getNode();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        int i, idx, n;
        n = word.size();
        TrieNode* cur = root;
        
        for (i = 0; i < n; i++) {
            idx = word[i] - 'a';
            if (cur->child[idx] == NULL)
                return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        int i, idx, n;
        string word = prefix;
        n = word.size();
        TrieNode* cur = root;
        
        for (i = 0; i < n; i++) {
            idx = word[i] - 'a';
            if (cur->child[idx] == NULL)
                return false;
            cur = cur->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
