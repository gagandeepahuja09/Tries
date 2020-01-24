class TrieNode {
    public:
    TrieNode* next[2];
    TrieNode() { next[0] = NULL; next[1] = NULL; }
};

class Solution {
public:
    void buildTree(TrieNode* root, vector<int>& nums) {
         for(int n : nums) {
            TrieNode* curr = root;
            for(int i = 31; i >= 0; i--) {
                int idx = (n & (1 << i)) >= 1 ? 1 : 0;
                if(curr -> next[idx] == NULL) {
                    curr -> next[idx] = new TrieNode;
                }
                curr = curr -> next[idx];
            }
        }
    }
    
    int maxXor(int num, TrieNode* curr) {
        int ret = 0;
        for(int i = 31; i >= 0; i--) {
            int idx = (num & (1 << i)) >= 1 ? 1 : 0;
            if(curr -> next[idx ^ 1]) {
                ret += (1 << i);
                curr = curr -> next[idx ^ 1];
            }
            else {
                curr = curr -> next[idx];
            }
        }
        return ret;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        buildTree(root, nums);
        int ret = 0;
        for(int n : nums) {
            ret = max(ret, maxXor(n, root));
        }
        return ret;
    }
};
