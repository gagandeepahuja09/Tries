class TrieNode {
    public:
        bool word;
        TrieNode* children[26];
        TrieNode() {
            word = false;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    bool search(string word, int i, TrieNode* node) {
        if(i == word.size())
            return node && node -> word;
        if(!node)
            return false;
        if(word[i] != '.')
                return search(word, i + 1, node -> children[word[i] - 'a']);
        for(int k = 0; k < 26; k++) {
            if(search(word, i + 1, node -> children[k])) {
                return true;
            }
        }
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
