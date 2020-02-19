class Trie {
    unordered_map<char, Trie*> next;
    bool wordEnds;
    
    public:
    Trie() {
        wordEnds = false;
    }
    void insert(string word) {
        Trie* temp = this;
        for(char ch : word) {
            if(temp -> next.find(ch) == temp -> next.end()) {
                temp -> next[ch] = new Trie();
            }
            temp = temp -> next[ch];
        }
        temp -> wordEnds = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for(char ch : word) {
            if(temp -> next.find(ch) == temp -> next.end()) {
                return false;
            }
            temp = temp -> next[ch];
            if(temp -> wordEnds)
                return true;
        }
        return temp -> wordEnds;
    }
};

class StreamChecker {
public:
    Trie trieNode;
    int maxLen = 0;
    string currStr;
    StreamChecker(vector<string>& words) {
        for(string word : words) {
            reverse(word.begin(), word.end());
            trieNode.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
    }
    
    bool query(char letter) {
        if(currStr.size() > maxLen)
            currStr.pop_back();
        currStr = letter + currStr;
        return trieNode.search(currStr);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
