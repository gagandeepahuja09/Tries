class TrieNode {
public:
    TrieNode* next[27];
    int weight;
    TrieNode(int w) {
        for(int i = 0; i < 27; i++) {
            next[i] = NULL;
        }
        weight = w;
    }
    
    void insert(TrieNode* root, string s, int i, int wt) {
        root -> weight = wt;
        if(i == s.size())
            return;
        int idx = s[i] - 'a';
        if(root -> next[idx] == NULL) {
            root -> next[idx] = new TrieNode(wt);
        }
        insert(root -> next[idx], s, i + 1, wt);
    }
};

class WordFilter {
public:
    TrieNode* root;
    WordFilter(vector<string>& words) {
        root = new TrieNode(0);
        for(int i = 0; i < words.size(); i++) {
            int wt = i;
            string word = words[i];
            while(word.size()) {
                TrieNode* temp = root;
                string curr = word + (char)('a' + 26) + words[i];
                root -> insert(temp, curr, 0, i);
                word = word.substr(1);
            }    
            string curr = (char)('a' + 26) + words[i];
            TrieNode* temp = root;
            root -> insert(temp, curr, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix + (char)('a' + 26) + prefix;
        TrieNode* temp = root;
        for(int i = 0; i < s.size(); i++) {
            if(!temp)
                return -1;
            temp = temp -> next[s[i] - 'a'];
        }
        return temp ? temp -> weight : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
