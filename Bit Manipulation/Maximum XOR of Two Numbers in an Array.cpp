class Node {
public:
    Node *left;
    Node *right;
    
    void insert(int value) {
        Node* curr = this;
        for (int i = 30; i >= 0; i --) {
            int bitmask = (value & (1 << i));
            if (bitmask == 0) {
                if (curr->left == NULL)
                    curr->left = new Node();
                
                curr = curr->left;
            } else {
                if (curr->right == NULL)
                    curr->right = new Node();
                
                curr = curr->right;
            }
        }
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for (int num : nums) {
            root->insert(num);
        }
        
        int maximumXOR = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int currXOR = 0;
            Node* curr = root;
            for (int j = 30; j >= 0; j --) {
                int value = (nums[i] & (1 << j));
                if (value == 0) {
                    if (curr->right != NULL) {
                        currXOR |= (1 << j);
                        curr = curr->right;
                    } else curr = curr->left;
                } else {
                    if (curr->left != NULL) {
                        currXOR |= (1 << j);
                        curr = curr->left;
                    } else curr = curr->right;
                }
            }
            
            maximumXOR = max(maximumXOR, currXOR);
        }
        
        return maximumXOR;
    }
};