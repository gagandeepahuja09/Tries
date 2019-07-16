class Trie {
    unordered_map<char, Trie*> char_map;
    bool word_ends;
    public:
        Trie() {
            word_ends = false;
        }
        
        void insert(string word) {
            if(!word.size())
                return;
            
            Trie *temp = this;
            for(auto ch : word) {
                if(temp -> char_map.find(ch) != temp -> char_map.end())
                    temp = temp -> char_map[ch];
                else {
                    temp -> char_map[ch] = new Trie();
                    temp = temp -> char_map[ch];
                }
            }
            temp -> word_ends = true;
        }
    
        bool search(string word) {
            if(!word.size())
                return false;
            Trie *temp = this;
            for(auto ch : word) {
                if(temp -> char_map.find(ch) == temp -> char_map.end()) {
                    return false;
                }
                temp = temp -> char_map[ch];
                if(temp -> word_ends)
                    return true;
            }
            return temp -> word_ends;
        }
};

class StreamChecker {
public:
    Trie my_trie;
    string str = "";
    int wLen = 0;
    StreamChecker(vector<string>& words) {
        for(auto w : words) {
            reverse(w.begin(), w.end());
            wLen = max(wLen, (int)w.length());
            my_trie.insert(w);
        }
    }
    
    bool query(char letter) {
        str = letter + str;
        if(str.length() > wLen)
            str.pop_back();
        return my_trie.search(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
