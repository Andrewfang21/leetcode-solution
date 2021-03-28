class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        this->children[0] = this->children[1] = NULL;
    }

    void insert(int number) {
        TrieNode* curr = this;
        for (int i = 30; i >= 0; i --) {
            int which = min((number & (1 << i)), 1);
            
            if (curr->children[which] == NULL) {
                curr->children[which] = new TrieNode();
            }
            curr = curr->children[which];
        }
    }
    
    int get(TrieNode* root, int currVal, int givenVal, int offset, int limit) {
        if (currVal > limit)
            return -1;
        if (offset < 0)
            return currVal ^ givenVal;

        int bit = min((givenVal & (1 << offset)), 1);
        
        if (root->children[1 - bit] != NULL) {
            int nextVal = get(root->children[1 - bit], (currVal | ((1 - bit) << offset)), givenVal, offset - 1, limit);
            if (nextVal >= 0)
                return nextVal;
        }
        
        if (root->children[bit] != NULL) {
            int nextVal = get(root->children[bit], (currVal | ((bit) << offset)), givenVal, offset - 1, limit);
            if (nextVal >= 0)
                return nextVal;
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode* root = new TrieNode();
        for (int num : nums)
            root->insert(num);
        
        vector<int> answer;
        for (vector<int> query : queries) {
            int givenVal = query[0];
            int limit = query[1];
            int currAnswer = root->get(root, 0, givenVal, 30, limit);
            answer.emplace_back(currAnswer);
        }
        
        return answer;
    }
};