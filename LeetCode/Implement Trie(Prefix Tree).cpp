class TrieNode {
    public:
        TrieNode* next[26];
        bool is_word;
        TrieNode() {
            is_word = false;
            memset(next, 0, sizeof next);
        }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp = root;
        for(int i = 0; i < word.size(); i++) {
            if(temp -> next[word[i] - 'a'] == NULL)
                temp -> next[word[i] - 'a'] = new TrieNode();
            temp = temp -> next[word[i] - 'a'];
        }
        temp -> is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p != NULL && p ->  is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
    
    private:
        TrieNode* find(string key) {
            TrieNode* temp = root;
            for(int i = 0; i < key.size() && temp != NULL; i++) {
                temp = temp -> next[key[i] - 'a'];
            }
            return temp;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
